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

char CoreData::get_value(const size_t x, const size_t y) const
{

    return data[x][y];
}

void CoreData::set_value(const size_t x, const size_t y, const Value val)
{
    char ch = ValueTools::get_char_from_value(val);
    data[x][y] = ch;
}

const Table<char> CoreData::create_empty_array() const
{
    return Table<char> {
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
