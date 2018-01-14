#include "TileWrapper.h"

TileWrapper::TileWrapper(const FieldTile tile) : data(tile)
{
    //ctor
}

TileWrapper::~TileWrapper()
{
    //dtor
}

TileWrapper::handle_type TileWrapper::create(const FieldTile tile)
{
    return handle_type(new TileWrapper(tile));
}

bool TileWrapper::is_solved() const
{
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (!(data[x][y]->is_set())) {
                return false;
            }
        }
    }

    return true;
}

bool TileWrapper::contains(const Value val) const
{
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (data[x][y]->is_set_to(val)) {
                return true;
            }
        }
    }

    return false;
}

size_t TileWrapper::possible_places_for(const Value val) const
{
    size_t result = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (data[x][y]->can_be(val)) {
                result++;
            }
        }
    }

    return result;
}

Position TileWrapper::first_acceptabe_position_for(const Value val) const
{
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (data[x][y]->can_be(val)) {
                return Position(x,y);
            }
        }
    }

    return Position(20,20);
}
