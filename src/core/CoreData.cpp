#include "CoreData.h"

#include <Logger.h>

namespace sudoku {

extern ui::Logger log;

namespace core {

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

const char CoreData::get_value(const Position pos) const
{

    return data[pos.get_x()][pos.get_y()];
}

void CoreData::set_value(const Slot slot)
{
    data[slot.get_x()][slot.get_y()] = ValueTools::get_char_from_value(slot.get_value());
    log(LogLevel_Debug) << "CDS Setting data field " << slot.to_string() << std::endl;
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

} // namespace core
} // namespace sudoku
