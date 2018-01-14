#include "Position.h"

#include <iostream>

Position::~Position()
{
    //dtor
}

Position::Position(const size_t xp, const size_t yp) : x(xp), y(yp)
{
    //ctor
}

size_t Position::get_x() const
{
    return x;
}

void Position::set_x(const size_t val)
{
    if (is_correct(x)) {
        x = val;
    }
}

size_t Position::get_y() const
{
    return y;
}

void Position::set_y(const size_t val)
{
    if (is_correct(val)) {
        y = val;
    }
}

bool Position::is_correct(const size_t val)
{
    if (val < 9) {
        return true;
    }

    //TODO error exception
    std::cout << "ERR Wrong position value: " << val << std::endl;
    return false;
}
