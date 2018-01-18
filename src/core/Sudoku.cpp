#include "Sudoku.h"

//TODO remove
#include <sstream>

#include <ColumnWrapper.h>
#include <Consts.h>
#include <CoreData.h>
#include <RowWrapper.h>
#include <TileWrapper.h>

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

//void Sudoku::set_value(const size_t x, const size_t y, const Value val)
void Sudoku::set_value(const Slot slot)
{
    // For undefined values do nothing
    if (slot.get_value() == Value_Undefined) {
        return;
    }

    board[slot.get_x()][slot.get_y()]->set_value(slot.get_value());

    // Mark in all fields in the same row that this value is already used
    FieldRow row = get_row(slot.get_y());
    loop (i, ROW_MAX) {
        row[i]->remove_possibility(slot.get_value());
    }

    // Repeat for column
    FieldColumn col = get_column(slot.get_x());
    loop (i, COLUMN_MAX) {
        col[i]->remove_possibility(slot.get_value());
    }

    // Repeat for tile
    FieldTile tile = get_tile(Position(slot.get_x(), slot.get_y()));
    loop (i, TILE_MAX_X) {
        loop (j, TILE_MAX_Y) {
            tile[i][j]->remove_possibility(slot.get_value());
        }
    }
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

FieldRow Sudoku::get_row(const size_t y) const
{
    FieldRow row = FieldRow();
    loop (x, BOARD_MAX_X) {
        row[x] = board[x][y];
    }
    return row;
}

FieldColumn Sudoku::get_column(const size_t x) const
{
    return board[x];
}

bool Sudoku::is_solved() const
{
    loop (x, BOARD_MAX_X) {
        ColumnWrapper::handle_type column = ColumnWrapper::create(get_column(x), x);
        if (!column->is_solved()) {
            return false;
        }
    }

    return true;
}

FieldTile Sudoku::get_tile(const size_t index) const
{
    FieldTile tile = FieldTile();

    const size_t start_x = (index % 3) * 3;
    const size_t start_y = (index / 3) * 3;

    loop (x, TILE_MAX_X) {
        loop(y, TILE_MAX_Y) {
            tile[x][y] = board[start_x + x][start_y + y];
        }
    }

    return tile;
}

FieldTile Sudoku::get_tile(const Position pos) const
{
    const size_t index = (pos.get_x() / 3) + (pos.get_y() / 3) * 3;
    return get_tile(index);
}

//const Position Sudoku::tile_to_board(const Position pos, const size_t i) const
//{
//    return Position((i % 3) * 3 + pos.get_x(), (i / 3) * 3 + pos.get_y());
//}

//Field::handle_type Sudoku::get_field(const size_t x, const size_t y) const
//{
//    return board[x][y];
//}

bool Sudoku::solve_step()
{
    for (auto alg : algorithms) {
        alg(*this);
    }

    if (found_fields.empty()) {
        return false;
    }

    for (auto found : found_fields) {
//        set_value(Slot(found.first.get_x(), found.first.get_y(), found.second));
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
        RowWrapper::handle_type row = RowWrapper::create(get_row(y), y);

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
//                    size_t x = row->first_acceptabe_position_for(val);
//                    found_fields.insert(Slot(x, y, val));

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
        ColumnWrapper::handle_type column = ColumnWrapper::create(get_column(x), x);

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
//                    size_t y = (column->first_acceptabe_position_for(val)).get_y();
//                    found_fields.insert(Slot(x, y, val));
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
        TileWrapper::handle_type tile = TileWrapper::create(get_tile(i), i);

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
//                    Position pos = tile_to_board(tile->first_acceptabe_position_for(val), i);
//                    found_fields.insert(Slot(pos, val));

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
