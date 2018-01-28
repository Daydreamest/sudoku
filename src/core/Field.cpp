#include "Field.h"

#include <sstream>

#include <Logger.h>

namespace sudoku {

extern ui::Logger log;

namespace core {

Field::Field() : field_value(Value_Undefined), possible_values(FieldPossibilities::create())
{
    // ctor
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
    if (field_value == v) {
        log(LogLevel_Warning) << "FST Field already has value " << field_value << ", not changing it" << v << std::endl;
        return;
    }

    if (field_value != Value_Undefined) {
        log(LogLevel_Warning) << "FST Field already has value " << field_value << ", changing it now to " << v << std::endl;
    }

    field_value = v;
    if (v != Value_Undefined) {
        possible_values->clear();
    }

    log(LogLevel_Debug) << "FST Changed field value to " << v << std::endl;
}

const Value Field::get_value() const
{
    return field_value;
}

const bool Field::is_set() const
{
    return field_value != Value_Undefined;
}

const bool Field::can_be(const Value v) const
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
    log(LogLevel_Debug) << "FRP Removed field possibility " << v << std::endl;
}

const std::string Field::to_string() const
{
    std::stringstream ss;

    ss << "Field (";

    if (is_set()) {
        ss << ValueTools::get_char_from_value(field_value);
    } else {
        ss << "Undefined";
    }

    ss << ") [";

    for (auto val : ValueTools::get_value_set()) {
        if (possible_values->contains(val)) {
            ss << ValueTools::get_char_from_value(val) << " ";
        }
    }

    ss << "]";

    return ss.str();
}

const size_t Field::get_number_of_possibilities() const
{
    if (is_set()) {
        log(LogLevel_Debug) << "FNP Field already set, it has no possibilities " << std::endl;
        return 0;
    }

    return possible_values->get_number_of_possibilities();
}

const Value Field::can_be_set() const
{
    if (get_number_of_possibilities() != 1) {
        return Value_Undefined;
    }

    return possible_values->get_unique_possibility();
}

const bool Field::is_set_to(const Value v) const
{
    if (!is_set()) {
        return false;
    }

    return (v == field_value);
}

} // namespace core
} // namespace sudoku
