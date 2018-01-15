#include "Position.h"

#include <iostream>

Position::~Position()
{
    //dtor
}

Position::Position(const size_t xp, const size_t yp) : x(xp), y(yp)
{
    //ctor
    if (!is_correct(9)) {
        // TODO throw exception
    }
}

size_t Position::get_x() const
{
    return x;
}

size_t Position::get_y() const
{
    return y;
}

bool Position::is_correct(const size_t val)
{
    if ((x < val) && (y < val)) {
        return true;
    }

    return false;
}

bool Position::operator==(const Position& other)
{
    return (x == other.x) && (y == other.y);
}

bool Position::operator<(const Position& other)
{
    if (x < other.x) {
        return true;
    }

    if (x > other.x) {
        return false;
    }

    return (y < other.y);
}
