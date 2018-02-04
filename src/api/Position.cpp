#include "Position.h"

#include <sstream>

#include <Consts.h>
#include <Logger.h>

namespace sudoku {

extern ui::Logger log;

Position::~Position()
{
    //dtor
}

Position::Position(const size_t xp, const size_t yp) : x(xp), y(yp)
{
    //ctor
    if (!is_correct(consts::BOARD_SIZE)) {
        log(LogLevel_Error) << "POC Incorrect position values" << std::endl;
        throw PositionException(x, y, consts::BOARD_SIZE);
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

const std::string Position::to_string() const
{
    std::stringstream ss;
    ss << "(" << x << "," << y << ")";
    return ss.str();
}

Position::PositionException::PositionException(const size_t xp, const size_t yp, const size_t max)
{
    // ctor
    std::stringstream ss;
    ss << "Trying to set position to (" << xp << ", " << yp << ") while max limit is " << max << std::endl;
    message = ss.str();
}

Position::PositionException::~PositionException()
{
    // dtor
}

} // namespace sudoku
