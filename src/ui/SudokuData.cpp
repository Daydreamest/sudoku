#include "SudokuData.h"

SudokuData::SudokuData() : data(create_empty_array())
{
    //ctor
}

SudokuData::~SudokuData()
{
    //dtor
}

SudokuRow<char> SudokuData::operator[](int x)
{
    if (x > 8) {
        // TODO log error
        return create_empty_row();
    }

    return data[x];
}

void SudokuData::set_value(const size_t x, const size_t y, const char value)
{
    // TODO mixed places to make it work
    data[y][x] = value;
}

void SudokuData::reset()
{
    data = create_empty_array();
}

const SudokuRow<char> SudokuData::create_empty_row() const
{
    return SudokuRow<char> {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
}

const SudokuTable<char> SudokuData::create_empty_array() const
{
    return SudokuTable<char> {
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
        ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
    };
}

SudokuData::handle_type SudokuData::create()
{
    return handle_type(new SudokuData);
}

char SudokuData::get_value(const size_t x, const size_t y) const
{
    return data[x][y];
}
