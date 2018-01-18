#include "TileWrapper.h"

#include <Consts.h>

TileWrapper::TileWrapper(const FieldTile tile, const size_t id) : AbstractWrapper(id), data(tile)
{
    //ctor
}

TileWrapper::~TileWrapper()
{
    //dtor
}

TileWrapper::handle_type TileWrapper::create(const FieldTile tile, const size_t id)
{
    return handle_type(new TileWrapper(tile, id));
}

bool TileWrapper::is_solved() const
{
    loop (x, TILE_MAX_X) {
        loop (y, TILE_MAX_Y) {
            if (!(data[x][y]->is_set())) {
                return false;
            }
        }
    }

    return true;
}

bool TileWrapper::contains(const Value val) const
{
    loop (x, TILE_MAX_X) {
        loop (y, TILE_MAX_Y) {
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
    loop (x, TILE_MAX_X) {
        loop (y, TILE_MAX_Y) {
            if (data[x][y]->can_be(val)) {
                result++;
            }
        }
    }

    return result;
}

Position TileWrapper::get_global_position(const Position pos) const
{
    return Position((index % 3) * 3 + pos.get_x(), (index / 3) * 3 + pos.get_y());
}

Position TileWrapper::first_position_for(const Value val) const
{
    loop (x, TILE_MAX_X) {
        loop (y, TILE_MAX_Y) {
            if (data[x][y]->can_be(val)) {
                return get_global_position(Position(x,y));
            }
        }
    }

    return Position(20,20);
}
void TileWrapper::sanitize(const Value val)
{
    if (contains(val)) {
        loop (x, TILE_MAX_X) {
            loop (y, TILE_MAX_Y) {
                data[x][y]->remove_possibility(val);
            }
        }
    }

}

