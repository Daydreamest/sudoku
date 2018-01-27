#ifndef CONSTS_H
#define CONSTS_H

#include <cstddef>

#define loop(x,n) for(size_t x = 0; x < n; ++x)

namespace sudoku {

const size_t BOARD_SIZE = 9;
const size_t TILE_SIZE = 3;

const size_t BOARD_MAX_X = BOARD_SIZE;
const size_t BOARD_MAX_Y = BOARD_SIZE;
const size_t ROW_MAX = BOARD_SIZE;
const size_t COLUMN_MAX = BOARD_SIZE;
const size_t TILE_MAX_X = TILE_SIZE;
const size_t TILE_MAX_Y = TILE_SIZE;
const size_t TILE_COUNT = (BOARD_MAX_X/TILE_MAX_X) * (BOARD_MAX_Y/TILE_MAX_Y);

class Consts
{
    public:
        Consts();
        virtual ~Consts();

    protected:

    private:
};

} // namespace sudoku

#endif // CONSTS_H
