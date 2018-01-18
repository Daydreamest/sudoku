#include "ColumnWrapper.h"

#include <Consts.h>

ColumnWrapper::ColumnWrapper(const FieldColumn col, const size_t id): AbstractWrapper(id), data(col)
{
    //ctor
}

ColumnWrapper::~ColumnWrapper()
{
    //dtor
}

ColumnWrapper::handle_type ColumnWrapper::create(const FieldColumn col, const size_t id)
{
    return handle_type(new ColumnWrapper(col, id));
}

bool ColumnWrapper::is_solved() const
{
    loop (y, COLUMN_MAX) {
        if (!(data[y]->is_set())) {
            return false;
        }
    }

    return true;
}

bool ColumnWrapper::contains(const Value val) const
{
    loop (y, COLUMN_MAX) {
        if (data[y]->is_set_to(val)) {
            return true;
        }
    }

    return false;
}

size_t ColumnWrapper::possible_places_for(const Value val) const
{
    size_t result = 0;
    loop (y, COLUMN_MAX) {
        if (data[y]->can_be(val)) {
            result++;
        }
    }

    return result;
}

Position ColumnWrapper::first_position_for(const Value val) const
{
    loop (y, COLUMN_MAX) {
        if (data[y]->can_be(val)) {
            return Position(index, y);
        }
    }

    return Position(20, 20);
}

void ColumnWrapper::sanitize(const Value val)
{
    if (contains(val)) {
        loop (x, COLUMN_MAX) {
            data[x]->remove_possibility(val);
        }
    }
}
