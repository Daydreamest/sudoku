#include "AlgorithmContainer.h"

#include <AlgorithmColumns.h>
#include <AlgorithmFields.h>
#include <AlgorithmRows.h>
#include <AlgorithmTiles.h>
#include <Logger.h>

namespace sudoku {

extern ui::Logger log;

namespace core {
namespace algorithm {

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
        log(LogLevel_Debug) << "ALR Running algorithm: " << algo->get_name() << std::endl;
        (*algo)();
    }
}

void AlgorithmContainer::initialize(BoardWrapper& brd, SlotSet& res)
{
    add(AlgorithmFields::create(brd, res));
    add(AlgorithmRows::create(brd, res));
    add(AlgorithmColumns::create(brd, res));
    add(AlgorithmTiles::create(brd, res));
}

} // namespace algorithm
} // namespace core
} // namespace sudoku
