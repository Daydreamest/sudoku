#include "UiData.h"

namespace sudoku {
namespace ui {

UiData::UiData() : data(create_empty_array())
{
    //ctor
}

UiData::~UiData()
{
    //dtor
}

void UiData::set_value(const Position pos, const char value)
{
    data[pos.get_x()][pos.get_y()] = value;
}

const Table<char> UiData::create_empty_array() const
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

UiData::handle_type UiData::create()
{
    return handle_type(new UiData);
}

const char UiData::get_value(const Position pos) const
{
    return data[pos.get_x()][pos.get_y()];
}

} //namespace ui
} // namespace sudoku
