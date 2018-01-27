#include "CoreData.h"

namespace sudoku {

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

char CoreData::get_value(const Position pos) const
{

    return data[pos.get_x()][pos.get_y()];
}

void CoreData::set_value(const Slot slot)
{
    char ch = ValueTools::get_char_from_value(slot.get_value());
    data[slot.get_x()][slot.get_y()] = ch;
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

} // namespace sudoku
