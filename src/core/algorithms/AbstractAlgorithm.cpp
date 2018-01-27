#include "AbstractAlgorithm.h"

namespace sudoku {

AbstractAlgorithm::AbstractAlgorithm(BoardWrapper& brd, SlotSet& res) : board(brd), results(res)
{
    //ctor
}

AbstractAlgorithm::~AbstractAlgorithm()
{
    //dtor
}

} // namespace sudoku
