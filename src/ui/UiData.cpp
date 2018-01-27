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

void UiData::set_value(const size_t x, const size_t y, const char value)
{
    data[x][y] = value;
}

void UiData::reset()
{
    data = create_empty_array();
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

char UiData::get_value(const Position pos) const
{
    return data[pos.get_x()][pos.get_y()];
}

} //namespace ui
} // namespace sudoku
