#include "FieldPossibilities.h"

// TODO remove
//#include <iostream>

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

void FieldPossibilities::remove(const Value v)
{
    possible_values.erase(v);
}

bool FieldPossibilities::contains(const Value v) const
{
//    std::cout << "Checking for value: " << v << std::endl;

    if (possible_values.count(v) > 0) {
//        std::cout << "    FOUND" << std::endl;
        return true;
    };
//    std::cout << "    NOT FOUND" << std::endl;
    return false;
}

FieldPossibilities::handle_type FieldPossibilities::create()
{
    return handle_type(new FieldPossibilities);
}
