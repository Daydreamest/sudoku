#include "TileWrapper.h"

#include <Consts.h>

TileWrapper::TileWrapper(const FieldTile tile, const size_t id) : AbstractWrapper(id, TILE_MAX_X * TILE_MAX_Y), data(tile)
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

Field::handle_type TileWrapper::get_field(const size_t i) const
{
    return data[i % 3][i / 3];
}

Position TileWrapper::get_global_position(const size_t i) const
{
    const size_t x = (ID % 3) * 3 + i % 3;
    const size_t y = (ID / 3) * 3 + i / 3;
    return Position(x, y);
}
