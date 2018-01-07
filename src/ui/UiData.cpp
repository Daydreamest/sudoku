#include "UiData.h"

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

char UiData::get_value(const size_t x, const size_t y) const
{
    return data[x][y];
}
