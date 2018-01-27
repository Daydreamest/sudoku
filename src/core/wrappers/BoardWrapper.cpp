#include "BoardWrapper.h"

#include <ColumnWrapper.h>
#include <Consts.h>
#include <Logger.h>
#include <RowWrapper.h>
#include <TileWrapper.h>

namespace sudoku {

extern ui::Logger log;

namespace core {

BoardWrapper::BoardWrapper() : board(create_empty_array())
{
    //ctor
}

BoardWrapper::~BoardWrapper()
{
    //dtor
}

void BoardWrapper::set_value(const Slot slot)
{
    // Set this field to the value
    board[slot.get_x()][slot.get_y()]->set_value(slot.get_value());
    log(LogLevel_Debug) << "STV set Field" << slot.to_string() << std::endl;

    // Mark in all fields in the same row that this value is already used
    get_row(slot.get_y())->sanitize(slot.get_value());
    log(LogLevel_Debug) << "STV Row(" << slot.get_y() << ") is sanitized" << std::endl;

    // Repeat for column
    get_column(slot.get_x())->sanitize(slot.get_value());
    log(LogLevel_Debug) << "STV Column(" << slot.get_x() << ") is sanitized" << std::endl;

    // Repeat for tile
    get_tile(slot.get_position())->sanitize(slot.get_value());
    log(LogLevel_Debug) << "STV Tile" << slot.get_position().to_string() << " is sanitized" << std::endl;

}

const FieldColumn& BoardWrapper::operator[](const size_t x) const
{
    return board[x];
}

AbstractWrapper::handle_type BoardWrapper::get_row(const size_t y) const
{
    FieldRow row = FieldRow();
    loop (x, consts::BOARD_MAX_X) {
        row[x] = board[x][y];
    }
    return std::move(RowWrapper::create(row, y));
}

AbstractWrapper::handle_type BoardWrapper::get_column(const size_t x) const
{
    return std::move(ColumnWrapper::create(board[x], x));
}

AbstractWrapper::handle_type BoardWrapper::get_tile(const size_t index) const
{
    FieldTile tile = FieldTile();

    const size_t start_x = (index % consts::TILE_MAX_X) * consts::TILE_MAX_X;
    const size_t start_y = (index / consts::TILE_MAX_Y) * consts::TILE_MAX_Y;

    loop (x, consts::TILE_MAX_X) {
        loop (y, consts::TILE_MAX_Y) {
            tile[x][y] = board[start_x + x][start_y + y];
        }
    }

    return std::move(TileWrapper::create(tile, index));
}

AbstractWrapper::handle_type BoardWrapper::get_tile(const Position pos) const
{
    const size_t index = (pos.get_x() / consts::TILE_MAX_X) + (pos.get_y() / consts::TILE_MAX_Y) * consts::TILE_MAX_Y;
    return std::move(get_tile(index));
}

const FieldRow BoardWrapper::create_empty_row() const
{
    FieldRow row = FieldRow();
    loop (i, consts::ROW_MAX) {
        row[i] = Field::create();
    }
    return row;
}

const FieldBoard BoardWrapper::create_empty_array() const
{
    FieldBoard table = FieldBoard();
    loop (i, consts::COLUMN_MAX) {
        table[i] = create_empty_row();
    }
    return table;
}

} // namespace core
} // namespace sudoku
