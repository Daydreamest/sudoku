#include "Slot.h"

#include <sstream>

namespace sudoku {
namespace core {

Slot::Slot(const size_t x, const size_t y, const Value v) : val(v), pos(x, y)
{
    //ctor
}

Slot::Slot(const Position p, const Value v) : val(v), pos(p)
{
    //ctor
}

Slot::~Slot()
{
    //dtor
}

const size_t Slot::get_x() const
{
    return pos.get_x();
}

const size_t Slot::get_y() const
{
    return pos.get_y();
}

const Value Slot::get_value() const
{
    return val;
}

const Position Slot::get_position() const
{
    return pos;
}

const std::string Slot::toString() const
{
    std::stringstream ss;
    ss << pos.toString() << " = " << val;
    return ss.str();
}

} // namespace core
} // namespace sudoku
