#include "Field.h"

#include <sstream> // TODO remove in the final release

Field::Field() : field_value(Value_Undefined), possible_values(FieldPossibilities::create())
{
    possible_values->reset();
}

Field::~Field()
{
     // dtor
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

const std::string Field::to_string() const
{
    std::stringstream ss;

    ss << "Field value: ";

    if (is_set()) {
        ss << ValueTools::get_char_from_value(field_value);
    } else {
        ss << "Undefined";
    }

    ss << std::endl << "Possible values are: (";

    for (auto val : ValueTools::get_value_set()) {
        if (possible_values->contains(val)) {
            ss << ValueTools::get_char_from_value(val) << " ";
        }
    }

    ss << ")" << std::endl;

    return ss.str();
}
