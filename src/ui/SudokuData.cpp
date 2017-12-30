#include "SudokuData.h"

UiData::UiData() : data(create_empty_array())
{
    //ctor
}

UiData::~UiData()
{
    //dtor
}

Row<char> UiData::operator[](int x)
{
    if (x > 8) {
        // TODO log error
        return create_empty_row();
    }

    return data[x];
}

void UiData::set_value(const size_t x, const size_t y, const char value)
{
    data[x][y] = value;
}

void UiData::reset()
{
    data = create_empty_array();
}

const Row<char> UiData::create_empty_row() const
{
    return Row<char> {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
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
