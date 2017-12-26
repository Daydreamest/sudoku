#include "Field.h"

Field::Field()
{
    //ctor
}

Field::~Field()
{
    //dtor
}

void Field::reset()
{

}

void Field::set_value(const SudokuValue v)
{

}

SudokuValue Field::get_value() const
{
    return Value_Undefined;
}

bool Field::is_set() const
{
    return false;
}

bool Field::can_be(const SudokuValue v) const
{
    return false;
}
