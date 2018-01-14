#include "Sudoku.h"

//TODO remove
#include <sstream>

#include <CoreData.h>
#include <RowWrapper.h>

Sudoku::Sudoku() : board(create_empty_array())
{
    //ctor
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
    for (int x = 0; x < 9; x++)
        for (int y = 0; y < 9; y++)
        {
            char ch_val = d->get_value(x, y);
            Value s_val = ValueTools::get_value_from_char(ch_val);

            set_value(x, y, s_val);
        }
}

const AbstractData::handle_type Sudoku::get_data() const
{
    CoreData::handle_type result = CoreData::create();

    for (int x = 0; x < 9; x++)
        for (int y = 0; y < 9; y++)
            if (board[x][y]->get_value() != Value_Undefined) {
                result->set_value(x, y, board[x][y]->get_value());
    }

    return result;
}

void Sudoku::set_value(const size_t x, const size_t y, const Value val)
{
    // TODO do magic checks
    board[x][y]->set_value(val);

    // Mark in all fields in the same row that this value is already used
    FieldRow row = get_row(y);
    for(size_t i = 0; i < 9; i++) {
        row[i]->remove_possibility(val);
    }

    // Repeat for column
    FieldColumn col = get_column(x);
    for(size_t i = 0; i < 9; i++) {
        col[i]->remove_possibility(val);
    }

    // Repeat for tile
    FieldTile tile = get_tile(x,y);
    for(size_t i = 0; i < 3; i++)
        for(size_t j = 0; j < 3; j++) {
            tile[i][j]->remove_possibility(val);
    }
}

const FieldRow Sudoku::create_empty_row() const
{
    FieldRow row = FieldRow();
    for (int i = 0; i < 9; i++) {
        row[i] = Field::create();
    }
    return row;
}

const FieldBoard Sudoku::create_empty_array() const
{
    FieldBoard table = FieldBoard();
    for (int i = 0; i < 9; i++) {
        table[i] = create_empty_row();
    }
    return table;
}

FieldRow Sudoku::get_row(const size_t y) const
{
    FieldRow row = FieldRow();
    for (int x = 0; x < 9; x++) {
        row[x] = board[x][y];
    }
    return row;
}

FieldColumn Sudoku::get_column(const size_t x) const
{
    return board[x];
}

FieldTile Sudoku::get_tile(const size_t index) const
{
    FieldTile tile = FieldTile();

    const size_t start_x = (index % 3) * 3;
    const size_t start_y = (index / 3) * 3;

    for (int x = 0; x < 3; x++)
        for (int y = 0; y < 3; y++) {
            tile[x][y] = board[start_x + x][start_y + y];
        }

    return tile;
}

FieldTile Sudoku::get_tile(const size_t x, const size_t y) const
{
    const size_t index = (x / 3) + (y / 3) * 3;
    return get_tile(index);
}

Field::handle_type Sudoku::get_field(const size_t x, const size_t y) const
{
    return board[x][y];
}

void Sudoku::solve()
{
    // Search for fields with 1 value possibility
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            Value val = board[x][y]->can_be_set();
            if (val != Value_Undefined) {
                std::stringstream ss;
                ss << "UFD Good inesrtion found! (" << x << ", " << y << ") = " << val << std::endl;
                log(ss.str());
            }
        }
    }

    // Search the rows for values that can be placed in single places only
    for (int y = 0; y < 9; y++) {

        RowWrapper::handle_type row = RowWrapper::create(get_row(y));

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
                    size_t x = row->first_acceptabe_position_for(val);
                    std::stringstream ss;
                    ss << "ROW Good inesrtion found! (" << x << ", " << y << ") = " << val << std::endl;
                    log(ss.str());
                } else {
//                    std::stringstream ss;
//                    ss << "ROW For value " << val << " there were " << places_for_val << " places found in row " << y << std::endl;
//                    log(ss.str());
                }
            }
        }
    }
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
    log_field(2, 2);
    log_field(7, 2);

/*    size_t x = 1, y = 2;
    std::stringstream ss1, ss2;

    std::cout << "Info about field (" << x << ", " << y << ")" << std::endl;

    ss1 << "Value: " << board[x][y]->get_value();
    log(ss1.str());

    ss2 << "Possible values: ";

    if (board[x][y]->can_be(Value_1)) {
        ss2 << 1 << ", ";
    }

    if (board[x][y]->can_be(Value_2)) {
        ss2 << 2 << ", ";
    }

    if (board[x][y]->can_be(Value_3)) {
        ss2 << 3 << ", ";
    }

    if (board[x][y]->can_be(Value_4)) {
        ss2 << 4 << ", ";
    }

    if (board[x][y]->can_be(Value_5)) {
        ss2 << 5 << ", ";
    }

    if (board[x][y]->can_be(Value_6)) {
        ss2 << 6 << ", ";
    }

    if (board[x][y]->can_be(Value_7)) {
        ss2 << 7 << ", ";
    }

    if (board[x][y]->can_be(Value_8)) {
        ss2 << 8 << ", ";
    }

    if (board[x][y]->can_be(Value_9)) {
        ss2 << 9 << ", ";
    }

    log(ss2.str());
    */
}
