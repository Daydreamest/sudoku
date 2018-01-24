#include "AlgorithmContainer.h"

#include <AlgorithmFields.h>
#include <Logger.h>

extern Logger log;

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

void AlgorithmContainer::initialize(FieldBoard& brd, SlotSet& res)
{
    //TODO check if doesn't exist already
    algorithms.push_back(AlgorithmFields::create(brd, res));
}
