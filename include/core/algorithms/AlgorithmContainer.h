#ifndef ALGORITHMCONTAINER_H
#define ALGORITHMCONTAINER_H

#include <memory>
#include <vector>

#include <AbstractAlgorithm.h>
#include <BoardWrapper.h>

class AlgorithmContainer
{
    public:
        using handle_type = std::shared_ptr<AlgorithmContainer>;

//        AlgorithmContainer(FieldBoard& brd, SlotSet& res);
        AlgorithmContainer();
        virtual ~AlgorithmContainer();

        void initialize(BoardWrapper& brd, SlotSet& res);

//        void remove_algorithm(AbstractAlgorithm::handle_type algo);

//        void set_result_container(SlotSet& res);
//
//        void set_board(FieldBoard& brd);

        void run();
    protected:

    private:
        void add(AbstractAlgorithm::handle_type algo);

        std::vector<AbstractAlgorithm::handle_type> algorithms;

//        FieldBoard& board;
//        SlotSet& result;
};

#endif // ALGORITHMCONTAINER_H
