#include "AbstractAlgorithm.h"

namespace sudoku {
namespace core {
namespace algorithm {

AbstractAlgorithm::AbstractAlgorithm(BoardWrapper& brd, SlotSet& res) : board(brd), results(res)
{
    //ctor
}

AbstractAlgorithm::~AbstractAlgorithm()
{
    //dtor
}

} // namespace algorithm
} // namespace core
} // namespace sudoku
