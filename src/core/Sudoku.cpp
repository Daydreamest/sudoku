#include "Sudoku.h"

#include <CoreData.h>

Sudoku::Sudoku() : data(create_empty_array())
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
            if (data[x][y]->get_value() != Value_Undefined) {
                result->set_value(x, y, data[x][y]->get_value());
    }

    return result;
}


void Sudoku::set_value(const size_t x, const size_t y, const SudokuValue val)
{
//    log("Hello world!");

    // TODO do magic checks
    data[x][y]->set_value(val);
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
    return data[i];
}

FieldColumn Sudoku::get_column(const size_t i) const
{
    FieldColumn col = FieldColumn();
    for (int j = 0; j < 9; j++) {
        col[j] = data[j][i];
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
            tile[i][j] = data[start_x + i][start_y + j];
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
    return data[x][y];
}