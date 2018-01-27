#include "TileWrapper.h"

#include <Consts.h>

namespace sudoku {
namespace core {

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
    return data[i % TILE_MAX_X][i / TILE_MAX_Y];
}

Position TileWrapper::get_global_position(const size_t i) const
{
    const size_t x = (ID % TILE_MAX_X) * TILE_MAX_X + i % TILE_MAX_X;
    const size_t y = (ID / TILE_MAX_Y) * TILE_MAX_Y + i / TILE_MAX_Y;
    return Position(x, y);
}

} // namespace core
} // namespace sudoku
