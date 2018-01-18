#include "Sudoku.h"

//TODO remove
#include <sstream>

#include <Consts.h>
#include <CoreData.h>

Sudoku::Sudoku() : board(create_empty_array())
{
    //ctor

    // Set algorithms
    algorithms.push_back(&Sudoku::algorithm_fields_with_single_possible_value);
    algorithms.push_back(&Sudoku::algorithm_only_feasible_place_in_a_row);
    algorithms.push_back(&Sudoku::algorithm_only_feasible_place_in_a_column);
    algorithms.push_back(&Sudoku::algorithm_only_feasible_place_in_a_tile);
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
                result->set_value(x, y, board[x][y]->get_value());
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

    board[slot.get_x()][slot.get_y()]->set_value(slot.get_value());

    // Mark in all fields in the same row that this value is already used
    get_row(slot.get_y())->sanitize(slot.get_value());

    // Repeat for column
    get_column(slot.get_x())->sanitize(slot.get_value());

    // Repeat for tile
    get_tile(slot.get_position())->sanitize(slot.get_value());
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

RowWrapper::handle_type Sudoku::get_row(const size_t y) const
{
    FieldRow row = FieldRow();
    loop (x, BOARD_MAX_X) {
        row[x] = board[x][y];
    }
    return std::move(RowWrapper::create(row, y));
}

ColumnWrapper::handle_type Sudoku::get_column(const size_t x) const
{
    return std::move(ColumnWrapper::create(board[x], x));
}

bool Sudoku::is_solved() const
{
    loop (x, BOARD_MAX_X) {
        ColumnWrapper::handle_type column = get_column(x);
        if (!column->is_solved()) {
            return false;
        }
    }

    return true;
}

TileWrapper::handle_type Sudoku::get_tile(const size_t index) const
{
    FieldTile tile = FieldTile();

    const size_t start_x = (index % 3) * 3;
    const size_t start_y = (index / 3) * 3;

    loop (x, TILE_MAX_X) {
        loop(y, TILE_MAX_Y) {
            tile[x][y] = board[start_x + x][start_y + y];
        }
    }

    return std::move(TileWrapper::create(tile, index));
}

TileWrapper::handle_type Sudoku::get_tile(const Position pos) const
{
    const size_t index = (pos.get_x() / 3) + (pos.get_y() / 3) * 3;
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

//        std::stringstream ss;
//        ss << "SLV found solution for field (" << found.first.get_x() << ", " << found.first.get_y() << ") = " << found.second;
//        log(ss.str());
    }
    found_fields.clear();

    return true;
//    TEST();
}

void Sudoku::log_field(const size_t x, const size_t y)
{
    std::stringstream ss;

    ss << "Info about field (" << x << ", " << y << ")";
    log(ss.str());

    log(board[x][y]->to_string());
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
//                std::stringstream ss;
//                ss << "FLD Good inesrtion found! (" << x << ", " << y << ") = " << val;
//                log(ss.str());
                found_fields.insert(Slot(x, y, val));
            }
        }
    }
}

void Sudoku::algorithm_only_feasible_place_in_a_row()
{
    // Search the rows for values that can be placed in single places only
    loop (y, BOARD_MAX_Y) {
        RowWrapper::handle_type row = get_row(y);

        if (row->is_solved()) {
            continue; // Already solved
        }

        for (auto val : ValueTools::get_value_set()) {
            if (!row->contains(val)) {

                size_t places = row->possible_places_for(val);

                if (places == 0) {
                    std::stringstream ss;
                    ss << "ROW Well shit, value " << val << " can't be placed in row " << y << std::endl;
                    log(ss.str());
                } else if (places == 1) {
                    found_fields.insert(Slot(row->first_position_for(val), val));
//                    std::stringstream ss;
//                    ss << "ROW Good inesrtion found! (" << x << ", " << y << ") = " << val;
//                    log(ss.str());
                } else {
//                    std::stringstream ss;
//                    ss << "ROW For value " << val << " there were " << places_for_val << " places found in row " << y << std::endl;
//                    log(ss.str());
                }
            }
        }
    }
}

void Sudoku::algorithm_only_feasible_place_in_a_column()
{
    // Search the columns for values that can be placed in single places only
    loop (x, BOARD_MAX_X) {
        ColumnWrapper::handle_type column = get_column(x);

        if (column->is_solved()) {
            continue; // Already solved
        }

        for (auto val : ValueTools::get_value_set()) {
            if (!column->contains(val)) {

                size_t places = column->possible_places_for(val);

                if (places == 0) {
                    std::stringstream ss;
                    ss << "COL Well shit, value " << val << " can't be placed in column " << x << std::endl;
                    log(ss.str());
                } else if (places == 1) {
                    found_fields.insert(Slot(column->first_position_for(val), val));
//                    std::stringstream ss;
//                    ss << "COL Good inesrtion found! (" << x << ", " << y << ") = " << val;
//                    log(ss.str());
                } else {
//                    std::stringstream ss;
//                    ss << "COL For value " << val << " there were " << places << " places found in column " << x << std::endl;
//                    log(ss.str());
                }
            }
        }
    }
}

void Sudoku::algorithm_only_feasible_place_in_a_tile()
{
    // Search the tiles for values that can be placed in single places only
    loop (i, TILE_COUNT) {
        TileWrapper::handle_type tile = get_tile(i);

        if (tile->is_solved()) {
            continue; // Already solved
        }

        for (auto val : ValueTools::get_value_set()) {
            if (!tile->contains(val)) {

                size_t places = tile->possible_places_for(val);

                if (places == 0) {
                    std::stringstream ss;
                    ss << "TIL Well shit, value " << val << " can't be placed in tile " << i << std::endl;
                    log(ss.str());
                } else if (places == 1) {
                    found_fields.insert(Slot(tile->first_position_for(val), val));

//                    std::stringstream ss;
//                    ss << "TIL Good inesrtion found! (" << pos.get_x() << ", " << pos.get_y() << ") = " << val;
//                    log(ss.str());
                } else {
//                    std::stringstream ss;
//                    ss << "TIL For value " << val << " there were " << places << " places found in tile " << i << std::endl;
//                    log(ss.str());
                }
            }
        }
    }
}
