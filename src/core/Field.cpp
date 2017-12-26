#include "Field.h"

Field::Field() : field_value(Value_Undefined), possible_values()
{
    reset();
}

Field::~Field()
{
    possible_values.clear();
}

void Field::reset()
{
    field_value = Value_Undefined;
    possible_values.clear();
    possible_values.insert(Value_1);
    possible_values.insert(Value_2);
    possible_values.insert(Value_3);
    possible_values.insert(Value_4);
    possible_values.insert(Value_5);
    possible_values.insert(Value_6);
    possible_values.insert(Value_7);
    possible_values.insert(Value_8);
    possible_values.insert(Value_9);
}

void Field::set_value(const SudokuValue v)
{
    field_value = v;
    possible_values.clear();
}

SudokuValue Field::get_value() const
{
    return field_value;
}

bool Field::is_set() const
{
    return field_value != Value_Undefined;
}

bool Field::can_be(const SudokuValue v) const
{
    auto position = possible_values.find(v);
    return position != possible_values.end();
}
