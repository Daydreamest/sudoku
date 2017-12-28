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

void FieldPossibilities::remove(const SudokuValue v)
{
    possible_values.erase(v);
}

bool FieldPossibilities::contains(const SudokuValue v) const
{
    auto position = possible_values.find(v);
    return position != possible_values.end();
}

FieldPossibilities::handle_type FieldPossibilities::create()
{
    return handle_type(new FieldPossibilities);
}
