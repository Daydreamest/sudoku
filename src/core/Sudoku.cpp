#include "Sudoku.h"

//TODO remove
#include <sstream>

#include <CoreData.h>

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
//    log("Set value");

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
//    return board[i];
}

FieldColumn Sudoku::get_column(const size_t x) const
{
//    FieldColumn col = FieldColumn();
//    for (int j = 0; j < 9; j++) {
//        col[j] = board[j][i];
//    }
//    return col;
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
    for (int i = 0; i < 9; i++) {
//        std::cout << "Reading row: " << i << std::endl;
        auto row = get_row(i);
        for (int j = 0; j < 9; j++) {
            auto field = row[j];
            ValueSet val_set;
            for (auto val : ValueTools::get_value_set()) {
                if (field->can_be(val)) {
                    val_set.insert(val);
                }
            }
            if (val_set.size() == 1) {
                std::stringstream ss;
                ss << "Good inesrtion found! (" << i << ", " << j << ") = " << *(val_set.begin()) << std::endl;
                log(ss.str());
//                log("Good inesrtion found!");
//                *logger << "Good inesrtion found!";
            }
        }
    }


    TEST();
}

void Sudoku::TEST()
{
    size_t x = 1, y = 2;
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
}
