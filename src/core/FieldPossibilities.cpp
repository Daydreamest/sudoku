#include "FieldPossibilities.h"

FieldPossibilities::FieldPossibilities() : possible_values()
{
    reset();
}

FieldPossibilities::~FieldPossibilities()
{
    possible_values.clear();
}

void FieldPossibilities::clear()
{
    possible_values.clear();
}

void FieldPossibilities::reset()
{
    possible_values.clear();
    for (Value val : ValueTools::get_value_set()) {
        possible_values.insert(val);
    }
//    possible_values.insert(Value_1);
//    possible_values.insert(Value_2);
//    possible_values.insert(Value_3);
//    possible_values.insert(Value_4);
//    possible_values.insert(Value_5);
//    possible_values.insert(Value_6);
//    possible_values.insert(Value_7);
//    possible_values.insert(Value_8);
//    possible_values.insert(Value_9);
}

void FieldPossibilities::remove(const Value v)
{
    possible_values.erase(v);
}

bool FieldPossibilities::contains(const Value v) const
{
    if (possible_values.count(v) > 0) {
        return true;
    };

    return false;
}

FieldPossibilities::handle_type FieldPossibilities::create()
{
    return handle_type(new FieldPossibilities);
}

size_t FieldPossibilities::get_number_of_possibilities() const
{
    return possible_values.size();
}

Value FieldPossibilities::get_unique_possibility() const
{
    if (get_number_of_possibilities() != 1) {
        return Value_Undefined;
    }

    return *(possible_values.cbegin());
}
