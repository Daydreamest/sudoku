#include "AlgorithmContainer.h"

#include <AlgorithmColumns.h>
#include <AlgorithmFields.h>
#include <AlgorithmRows.h>
#include <AlgorithmTiles.h>
#include <Logger.h>

namespace sudoku {

extern ui::Logger log;

//AlgorithmContainer::AlgorithmContainer(FieldBoard& brd, SlotSet& res) : board(brd), result(res)
AlgorithmContainer::AlgorithmContainer()
{
    //ctor
}

AlgorithmContainer::~AlgorithmContainer()
{
    //dtor
}

void AlgorithmContainer::add(AbstractAlgorithm::handle_type algo)
{
    //TODO check if doesn't exist already
    algorithms.push_back(algo);
}

void AlgorithmContainer::run()
{
    for (auto algo : algorithms) {
        log(Log_Level_Debug) << "ALR Running algorithm: " << algo->get_name() << std::endl;
        (*algo)();
    }
}

void AlgorithmContainer::initialize(BoardWrapper& brd, SlotSet& res)
{
    //TODO check if doesn't exist already
    algorithms.push_back(AlgorithmFields::create(brd, res));
    algorithms.push_back(AlgorithmRows::create(brd, res));
    algorithms.push_back(AlgorithmColumns::create(brd, res));
    algorithms.push_back(AlgorithmTiles::create(brd, res));
}

} // namespace sudoku
