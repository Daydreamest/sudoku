#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

#include <memory>

#include <BoardWrapper.h>
#include <Slot.h>

class AbstractAlgorithm
{
    public:
        using handle_type = std::shared_ptr<AbstractAlgorithm>;

        AbstractAlgorithm(BoardWrapper& brd, SlotSet& res);
        virtual ~AbstractAlgorithm();

        virtual void operator()() = 0;

        virtual std::string get_name() = 0;

    protected:
        BoardWrapper& board;
        SlotSet& results;

    private:
};

#endif // ABSTRACTALGORITHM_H
