#include "RowWrapper.h"

RowWrapper::RowWrapper(const FieldRow row) : data(row)
{
    //ctor
}

RowWrapper::~RowWrapper()
{
    //dtor
}

RowWrapper::handle_type RowWrapper::create(const FieldRow row)
{
    return handle_type(new RowWrapper(row));
}

bool RowWrapper::is_solved() const
{
    for (int x = 0; x < 9; x++) {
        if (!(data[x]->is_set())) {
            return false;
        }
    }

    return true;
}

bool RowWrapper::contains(const Value val) const
{
    for (int x = 0; x < 9; x++) {
        if (data[x]->is_set_to(val)) {
            return true;
        }
    }

    return false;
}

size_t RowWrapper::possible_places_for(const Value val) const
{
    size_t result = 0;
    for (int x = 0; x < 9; x++) {
        if (data[x]->can_be(val)) {
            result++;
        }
    }

    return result;
}

size_t RowWrapper::first_acceptabe_position_for(const Value val) const
{
    for (size_t x = 0; x < 9; x++) {
        if (data[x]->can_be(val)) {
            return x;
        }
    }

    return 20;
}
