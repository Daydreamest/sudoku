#include "Board.h"

#include <CoreData.h>

SudokuBoard::SudokuBoard() : data(create_empty_array())
{
    //ctor
}

SudokuBoard::~SudokuBoard()
{
    //dtor
}

SudokuBoard::handle_type SudokuBoard::create()
{
    return handle_type(new SudokuBoard);
}

void SudokuBoard::set_data(const AbstractSudokuData::handler_type d)
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            char ch_val = (*d)[i][j];
            SudokuValue s_val = SudokuValueTools::get_value_from_char(ch_val);

            set_value(j, i, s_val);
        }
}

const AbstractSudokuData::handler_type SudokuBoard::get_data() const
{
    CoreData::handle_type result = CoreData::create();

    for (int x = 0; x < 9; x++)
        for (int y = 0; y < 9; y++)
            if (data[x][y]->get_value() != Value_Undefined) {
                result->set_value(x, y, data[x][y]->get_value());
    }

    return result;
}


void SudokuBoard::set_value(const size_t x, const size_t y, const SudokuValue val)
{
//    log("Hello world!");

    // TODO do magic checks
    data[x][y]->set_value(val);
}

const SudokuRow<Field::handle_type> SudokuBoard::create_empty_row() const
{
    SudokuRow<Field::handle_type> row = SudokuRow<Field::handle_type>();
    for (int i = 0; i < 9; i++) {
        row[i] = Field::create();
    }
    return row;
}

const SudokuTable<Field::handle_type> SudokuBoard::create_empty_array() const
{
    SudokuTable<Field::handle_type> table = SudokuTable<Field::handle_type>();
    for (int i = 0; i < 9; i++) {
        table[i] = create_empty_row();
    }
    return table;
}

SudokuRow<Field::handle_type> SudokuBoard::get_row(const size_t i) const
{
    return data[i];
}

SudokuColumn<Field::handle_type> SudokuBoard::get_column(const size_t i) const
{
    SudokuColumn<Field::handle_type> col = SudokuColumn<Field::handle_type>();
    for (int j = 0; j < 9; j++) {
        col[j] = data[j][i];
    }
    return col;
}

SudokuTile<Field::handle_type> SudokuBoard::get_tile(const size_t index) const
{
    SudokuTile<Field::handle_type> tile = SudokuTile<Field::handle_type>();

    const size_t start_x = (index % 3) * 3;
    const size_t start_y = (index / 3) * 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            tile[i][j] = data[start_x + i][start_y + j];
        }

    return tile;
}

SudokuTile<Field::handle_type> SudokuBoard::get_tile(const size_t x, const size_t y) const
{
    const size_t index = (x / 3) + (y / 3) * 3;
    return get_tile(index);
}

Field::handle_type SudokuBoard::get_field(const size_t x, const size_t y) const
{
    return data[x][y];
}
