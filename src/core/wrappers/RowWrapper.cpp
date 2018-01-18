#include "RowWrapper.h"

#include <Consts.h>

RowWrapper::RowWrapper(const FieldRow row, const size_t id) : AbstractWrapper(id), data(row)
{
    //ctor
}

RowWrapper::~RowWrapper()
{
    //dtor
}

RowWrapper::handle_type RowWrapper::create(const FieldRow row, const size_t id)
{
    return handle_type(new RowWrapper(row, id));
}

bool RowWrapper::is_solved() const
{
    loop (x, ROW_MAX) {
        if (!(data[x]->is_set())) {
            return false;
        }
    }

    return true;
}

bool RowWrapper::contains(const Value val) const
{
    loop (x, ROW_MAX) {
        if (data[x]->is_set_to(val)) {
            return true;
        }
    }

    return false;
}

size_t RowWrapper::possible_places_for(const Value val) const
{
    size_t result = 0;
    loop (x, ROW_MAX) {
        if (data[x]->can_be(val)) {
            result++;
        }
    }

    return result;
}

Position RowWrapper::first_position_for(const Value val) const
{
    loop (x, ROW_MAX) {
        if (data[x]->can_be(val)) {
            return Position(x, index);
        }
    }

    return Position(20, 20);
}

void RowWrapper::sanitize(const Value val)
{
    if (contains(val)) {
        loop (x, ROW_MAX) {
            data[x]->remove_possibility(val);
        }
    }
}
