#include "Board.h"

SudokuBoard::SudokuBoard() : data()
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

void SudokuBoard::set_value(const size_t x, const size_t y, const SudokuValue val)
{
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

SudokuRow<Field::handle_type> SudokuBoard::get_row(size_t i) const
{
    return data[i];
}

SudokuColumn<Field::handle_type> SudokuBoard::get_column(size_t i) const
{
    SudokuColumn<Field::handle_type> col = SudokuColumn<Field::handle_type>();
    for (int j = 0; j < 9; j++) {
        col[j] = data[j][i];
    }
    return col;
}

SudokuTile<Field::handle_type> SudokuBoard::get_tile(size_t i) const
{
    SudokuTile<Field::handle_type> tile = SudokuTile<Field::handle_type>();

    // TODO fill it up with proper fields

    return tile;
}

SudokuTile<Field::handle_type> SudokuBoard::get_tile(size_t x, size_t y) const
{
    return get_tile(1);
}

Field::handle_type SudokuBoard::get_field(size_t x, size_t y) const
{
    return data[x][y];
}

