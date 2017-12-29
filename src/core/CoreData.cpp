#include "CoreData.h"

CoreData::CoreData() : data(create_empty_array())
{
    //ctor
}

CoreData::~CoreData()
{
    //dtor
}

CoreData::handle_type CoreData::create()
{
    return handle_type(new CoreData);
}

SudokuRow<char> CoreData::operator[](int x)
{
    return data[x];
}

char CoreData::get_value(const size_t x, const size_t y) const
{
    return data[x][y];
}

void CoreData::set_value(const size_t x, const size_t y, const SudokuValue val)
{
    char ch = SudokuValueTools::get_char_from_value(val);
    data[x][y] = ch;
}

const SudokuRow<char> CoreData::create_empty_row() const
{
    return SudokuRow<char> {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
}

const SudokuTable<char> CoreData::create_empty_array() const
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
