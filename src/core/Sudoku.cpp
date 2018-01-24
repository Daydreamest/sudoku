#include "Sudoku.h"

#include <ColumnWrapper.h>
#include <Consts.h>
#include <CoreData.h>
#include <Logger.h>
#include <RowWrapper.h>
#include <TileWrapper.h>

extern Logger log;

Sudoku::Sudoku() : board(create_empty_array())
{
    //ctor

    // Set algorithms
    algorithms.push_back(&Sudoku::algorithm_fields_with_single_possible_value);
    algorithms.push_back(&Sudoku::algorithm_only_feasible_place_in_a_row);
    algorithms.push_back(&Sudoku::algorithm_only_feasible_place_in_a_column);
    algorithms.push_back(&Sudoku::algorithm_only_feasible_place_in_a_tile);

//    algorithms2.add(Algorithm1::create(board, found_fields));
}

Sudoku::~Sudoku()
{
    //dtor
}

Sudoku::handle_type Sudoku::create()
{
    return handle_type(new Sudoku);
}

void Sudoku::set_data(const AbstractData::handle_type d)
{
    loop (x, BOARD_MAX_X) {
        loop (y, BOARD_MAX_Y) {
            char ch_val = d->get_value(Position(x, y));
            Value s_val = ValueTools::get_value_from_char(ch_val);

            set_value(Slot(x, y, s_val));
        }
    }
}

const AbstractData::handle_type Sudoku::get_data() const
{
    CoreData::handle_type result = CoreData::create();

    loop (x, BOARD_MAX_X) {
        loop (y, BOARD_MAX_Y) {
            if (board[x][y]->get_value() != Value_Undefined) {
                result->set_value(Slot(x, y, board[x][y]->get_value()));
            }
        }
    }

    return result;
}

void Sudoku::set_value(const Slot slot)
{
    // For undefined values do nothing
    if (slot.get_value() == Value_Undefined) {
        return;
    }

    // Set this field to the value
    board[slot.get_x()][slot.get_y()]->set_value(slot.get_value());
    log(Log_Level_Debug) << "STV set Field" << slot.toString() << std::endl;

    // Mark in all fields in the same row that this value is already used
    get_row(slot.get_y())->sanitize(slot.get_value());
    log(Log_Level_Debug) << "STV Row(" << slot.get_y() << ") is sanitized" << std::endl;

    // Repeat for column
    get_column(slot.get_x())->sanitize(slot.get_value());
    log(Log_Level_Debug) << "STV Column(" << slot.get_x() << ") is sanitized" << std::endl;

    // Repeat for tile
    get_tile(slot.get_position())->sanitize(slot.get_value());
    log(Log_Level_Debug) << "STV Tile" << slot.get_position().toString() << " is sanitized" << std::endl;
}

const FieldRow Sudoku::create_empty_row() const
{
    FieldRow row = FieldRow();
    loop (i, ROW_MAX) {
        row[i] = Field::create();
    }
    return row;
}

const FieldBoard Sudoku::create_empty_array() const
{
    FieldBoard table = FieldBoard();
    loop (i, COLUMN_MAX) {
        table[i] = create_empty_row();
    }
    return table;
}

AbstractWrapper::handle_type Sudoku::get_row(const size_t y) const
{
    FieldRow row = FieldRow();
    loop (x, BOARD_MAX_X) {
        row[x] = board[x][y];
    }
    return std::move(RowWrapper::create(row, y));
}

AbstractWrapper::handle_type Sudoku::get_column(const size_t x) const
{
    return std::move(ColumnWrapper::create(board[x], x));
}

bool Sudoku::is_solved() const
{
    loop (x, BOARD_MAX_X) {
        auto column = get_column(x);
        if (!column->is_solved()) {
            return false;
        }
    }

    return true;
}

AbstractWrapper::handle_type Sudoku::get_tile(const size_t index) const
{
    FieldTile tile = FieldTile();

    const size_t start_x = (index % TILE_MAX_X) * TILE_MAX_X;
    const size_t start_y = (index / TILE_MAX_Y) * TILE_MAX_Y;

    loop (x, TILE_MAX_X) {
        loop (y, TILE_MAX_Y) {
            tile[x][y] = board[start_x + x][start_y + y];
        }
    }

    return std::move(TileWrapper::create(tile, index));
}

AbstractWrapper::handle_type Sudoku::get_tile(const Position pos) const
{
    const size_t index = (pos.get_x() / TILE_MAX_X) + (pos.get_y() / TILE_MAX_Y) * TILE_MAX_Y;
    return std::move(get_tile(index));
}

bool Sudoku::solve_step()
{
    for (auto alg : algorithms) {
        alg(*this);
    }

    if (found_fields.empty()) {
        return false;
    }

    for (auto found : found_fields) {
        set_value(found);
        log(Log_Level_Info) << "SLV found solution for field " << found.toString() << std::endl;
    }
    found_fields.clear();

    return true;
//    TEST();
}

void Sudoku::log_field(const size_t x, const size_t y)
{
    log(Log_Level_Info) << "Info about field (" << x << ", " << y << ")" << std::endl;

    log(Log_Level_Info) << board[x][y]->to_string();
}

void Sudoku::TEST()
{

//    log_field(2, 2);
//    log_field(7, 2);
}

void Sudoku::algorithm_fields_with_single_possible_value()
{
    // Search for fields with 1 value possibility
    loop (x, BOARD_MAX_X) {
        loop (y, BOARD_MAX_Y) {
            Value val = board[x][y]->can_be_set();
            if (val != Value_Undefined) {
//                log << "FLD Good inesrtion found! (" << x << ", " << y << ") = " << val << std::endl;
                found_fields.insert(Slot(x, y, val));
            }
        }
    }
}

void Sudoku::algorithm_only_feasible_place_in_a_row()
{
    // Search the rows for values that can be placed in single places only
    loop (y, BOARD_MAX_Y) {
        auto row = get_row(y);

        if (row->is_solved()) {
            continue; // Already solved
        }

        for (auto val : ValueTools::get_value_set()) {
            if (!row->contains(val)) {

                size_t places = row->possible_places_for(val);

                if (places == 0) {
                    log(Log_Level_Error) << "ROW Well shit, value " << val << " can't be placed in row " << y << std::endl;
                } else if (places == 1) {
                    found_fields.insert(Slot(row->first_position_for(val), val));
//                    log << "ROW Good inesrtion found! (" << x << ", " << y << ") = " << val << std::endl;
                } else {
//                    log << "ROW For value " << val << " there were " << places_for_val << " places found in row " << y << std::endl;
                }
            }
        }
    }
}

void Sudoku::algorithm_only_feasible_place_in_a_column()
{
    // Search the columns for values that can be placed in single places only
    loop (x, BOARD_MAX_X) {
        auto column = get_column(x);

        if (column->is_solved()) {
            continue; // Already solved
        }

        for (auto val : ValueTools::get_value_set()) {
            if (!column->contains(val)) {

                size_t places = column->possible_places_for(val);

                if (places == 0) {
                    log(Log_Level_Error) << "COL Well shit, value " << val << " can't be placed in column " << x << std::endl;
                } else if (places == 1) {
                    found_fields.insert(Slot(column->first_position_for(val), val));
//                    log << "COL Good inesrtion found! (" << x << ", " << y << ") = " << val;
                } else {
//                    log << "COL For value " << val << " there were " << places << " places found in column " << x << std::endl;
                }
            }
        }
    }
}

void Sudoku::algorithm_only_feasible_place_in_a_tile()
{
    // Search the tiles for values that can be placed in single places only
    loop (i, TILE_COUNT) {
        auto tile = get_tile(i);

        if (tile->is_solved()) {
            continue; // Already solved
        }

        for (auto val : ValueTools::get_value_set()) {
            if (!tile->contains(val)) {

                size_t places = tile->possible_places_for(val);

                if (places == 0) {
                    log(Log_Level_Error) << "TIL Well shit, value " << val << " can't be placed in tile " << i << std::endl;
                } else if (places == 1) {
                    found_fields.insert(Slot(tile->first_position_for(val), val));
//                    log << "TIL Good inesrtion found! (" << pos.get_x() << ", " << pos.get_y() << ") = " << val << std::endl;
                } else {
//                    log << "TIL For value " << val << " there were " << places << " places found in tile " << i << std::endl;
                }
            }
        }
    }
}
