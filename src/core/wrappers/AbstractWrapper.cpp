#include "AbstractWrapper.h"

#include <Consts.h>

namespace sudoku {
namespace core {

AbstractWrapper::AbstractWrapper(const size_t id, const size_t max_index): ID(id), MAX_INDEX(max_index)
{
    //ctor
}

AbstractWrapper::~AbstractWrapper()
{
    //dtor
}

bool AbstractWrapper::is_solved() const
{
    loop (i, MAX_INDEX) {
        if (!(get_field(i)->is_set())) {
            return false;
        }
    }

    return true;
}

bool AbstractWrapper::contains(const Value val) const
{
    loop (i, MAX_INDEX) {
        if (get_field(i)->is_set_to(val)) {
            return true;
        }
    }

    return false;
}

size_t AbstractWrapper::possible_places_for(const Value val) const
{
    size_t result = 0;

    loop (i, MAX_INDEX) {
        if (get_field(i)->can_be(val)) {
            result++;
        }
    }

    return result;
}

Position AbstractWrapper::first_position_for(const Value val) const
{
    loop (i, MAX_INDEX) {
        if (get_field(i)->can_be(val)) {
            return get_global_position(i);
        }
    }

    return Position(20,20);
}

void AbstractWrapper::sanitize(const Value val)
{
    if (contains(val)) {
        loop (i, MAX_INDEX) {
            get_field(i)->remove_possibility(val);
        }
    }
}

} // namespace core
} // namespace sudoku
