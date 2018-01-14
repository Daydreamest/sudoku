#include "ColumnWrapper.h"

ColumnWrapper::ColumnWrapper(const FieldColumn col): data(col)
{
    //ctor
}

ColumnWrapper::~ColumnWrapper()
{
    //dtor
}

ColumnWrapper::handle_type ColumnWrapper::create(const FieldColumn col)
{
    return handle_type(new ColumnWrapper(col));
}

bool ColumnWrapper::is_solved() const
{
    for (size_t y = 0; y < 9; y++) {
        if (!(data[y]->is_set())) {
            return false;
        }
    }

    return true;
}

bool ColumnWrapper::contains(const Value val) const
{
    for (int y = 0; y < 9; y++) {
        if (data[y]->is_set_to(val)) {
            return true;
        }
    }

    return false;
}

size_t ColumnWrapper::possible_places_for(const Value val) const
{
    size_t result = 0;
    for (int y = 0; y < 9; y++) {
        if (data[y]->can_be(val)) {
            result++;
        }
    }

    return result;
}

size_t ColumnWrapper::first_acceptabe_position_for(const Value val) const
{
    for (size_t y = 0; y < 9; y++) {
        if (data[y]->can_be(val)) {
            return y;
        }
    }

    return 20;
}
