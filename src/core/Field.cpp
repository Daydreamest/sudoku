#include "Field.h"

Field::Field() : field_value(Value_Undefined), possible_values(FieldPossibilities::create())
{
    possible_values->reset();
}

Field::~Field()
{
}

void Field::reset()
{
    field_value = Value_Undefined;
    possible_values->reset();
}

void Field::set_value(const Value v)
{
    field_value = v;
    if (v != Value_Undefined) {
        possible_values->clear();
    }
}

Value Field::get_value() const
{
    return field_value;
}

bool Field::is_set() const
{
    return field_value != Value_Undefined;
}

bool Field::can_be(const Value v) const
{
    return possible_values->contains(v);
}

Field::handle_type Field::create()
{
    return handle_type(new Field);
}

void Field::remove_possibility(const Value v)
{
    possible_values->remove(v);
}
