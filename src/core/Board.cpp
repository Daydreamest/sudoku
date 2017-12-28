#include "Board.h"

SudokuBoard::SudokuBoard() : data()
{
    //ctor
}

SudokuBoard::~SudokuBoard()
{
    //dtor
}

SudokuBoard::handle_type SudokuBoard::create()
{
    return handle_type(new SudokuBoard);
}
