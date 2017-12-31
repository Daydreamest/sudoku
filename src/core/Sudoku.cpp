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
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            char ch_val = (*d)[i][j];
            SudokuValue s_val = SudokuValueTools::get_value_from_char(ch_val);

            set_value(j, i, s_val);
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

void Sudoku::set_value(const size_t x, const size_t y, const SudokuValue val)
{
//    log("Set value");

    // TODO do magic checks
    board[x][y]->set_value(val);

    // Mark in all fields in the same row that this value is already used
    FieldRow row = get_row(x);
    for(size_t i = 0; i < 9; i++) {
        row[i]->remove_possibility(val);
    }

    // Repeat for column
    FieldColumn col = get_column(y);
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

FieldRow Sudoku::get_row(const size_t i) const
{
    return board[i];
}

FieldColumn Sudoku::get_column(const size_t i) const
{
    FieldColumn col = FieldColumn();
    for (int j = 0; j < 9; j++) {
        col[j] = board[j][i];
    }
    return col;
}

FieldTile Sudoku::get_tile(const size_t index) const
{
    FieldTile tile = FieldTile();

    const size_t start_x = (index % 3) * 3;
    const size_t start_y = (index / 3) * 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            tile[i][j] = board[start_x + i][start_y + j];
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

void Sudoku::TEST()
{
/*
    std::stringstream ss1, ss2;
    log("Info about field: 0, 1");
    size_t x = 0, y = 1;

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
