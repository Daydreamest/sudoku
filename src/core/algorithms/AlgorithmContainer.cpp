#include "AlgorithmContainer.h"

AlgorithmContainer::AlgorithmContainer(FieldBoard& brd, SlotSet& res) : board(brd), result(res)
{
    //ctor
}

AlgorithmContainer::~AlgorithmContainer()
{
    //dtor
}

void AlgorithmContainer::add_algorithm(AbstractAlgorithm::handle_type algo)
{
    //TODO check if doesn't exist already
    algorithms.push_back(algo);
}

void AlgorithmContainer::run()
{
    for (auto algo : algorithms) {
        (*algo)();
    }
}
