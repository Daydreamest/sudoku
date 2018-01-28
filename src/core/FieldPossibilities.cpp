#include "FieldPossibilities.h"

namespace sudoku {
namespace core {

FieldPossibilities::FieldPossibilities() : possible_values()
{
    reset();
}

FieldPossibilities::~FieldPossibilities()
{
    clear();
}

void FieldPossibilities::clear()
{
    possible_values.clear();
}

void FieldPossibilities::reset()
{
    clear();
    for (Value val : ValueTools::get_value_set()) {
        possible_values.insert(val);
    }
}

void FieldPossibilities::remove(const Value v)
{
    possible_values.erase(v);
}

const bool FieldPossibilities::contains(const Value v) const
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

const size_t FieldPossibilities::get_number_of_possibilities() const
{
    return possible_values.size();
}

const Value FieldPossibilities::get_unique_possibility() const
{
    if (get_number_of_possibilities() != 1) {
        return Value_Undefined;
    }

    return *(possible_values.cbegin());
}

} // namespace core
} // namespace sudoku
