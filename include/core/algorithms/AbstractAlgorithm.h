#ifndef ABSTRACTALGORITHM_H
#define ABSTRACTALGORITHM_H

#include <memory>

#include <BoardWrapper.h>
#include <Slot.h>

namespace sudoku {
namespace core {
namespace algorithm {

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

} // namespace algorithm
} // namespace core
} // namespace sudoku

#endif // ABSTRACTALGORITHM_H
