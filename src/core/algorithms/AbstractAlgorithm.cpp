#include "AbstractAlgorithm.h"

namespace sudoku {
namespace core {

AbstractAlgorithm::AbstractAlgorithm(BoardWrapper& brd, SlotSet& res) : board(brd), results(res)
{
    //ctor
}

AbstractAlgorithm::~AbstractAlgorithm()
{
    //dtor
}

} // namespace core
} // namespace sudoku
