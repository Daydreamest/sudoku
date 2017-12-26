#include "SudokuData.h"

SudokuData::SudokuData() : data(create_empty_array())
{
    //ctor
}

SudokuData::~SudokuData()
{
    //dtor
}

std::array<char, 9> SudokuData::operator[](int x)
{
    if (x > 8) {
        // TODO log error
        return create_empty_row();
    }

    return data[x];
}

void SudokuData::set_value(const size_t x, const size_t y, const char value)
{
    data[x][y] = value;
}

void SudokuData::reset()
{
    data = create_empty_array();
}

const std::array<char, 9> SudokuData::create_empty_row() const
{
    return std::array<char, 9> {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
}

const Matrix<char, 9, 9> SudokuData::create_empty_array() const
{
    return Matrix<char, 9, 9> {
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
