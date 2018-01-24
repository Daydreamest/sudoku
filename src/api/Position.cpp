#include "Position.h"

#include <sstream>

#include <Consts.h>
#include <Logger.h>

extern Logger log;

Position::~Position()
{
    //dtor
}

Position::Position(const size_t xp, const size_t yp) : x(xp), y(yp)
{
    //ctor
    if (!is_correct(BOARD_SIZE)) {
        log(Log_Level_Error) << "POC Tring to set position to " << toString() << " while max limit is " << BOARD_SIZE << std::endl;;
        log(Log_Level_Error) << "POC Throwing exception..." << std::endl;;
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

const std::string Position::toString() const
{
    std::stringstream ss;
    ss << "(" << x << "," << y << ")";
    return ss.str();
}
