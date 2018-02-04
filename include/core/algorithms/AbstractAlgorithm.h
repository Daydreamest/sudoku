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
        // Handle type definition
        using handle_type = std::shared_ptr<AbstractAlgorithm>;

        // Constructor
        AbstractAlgorithm(BoardWrapper& brd, SlotSet& res);

        // Destructor
        virtual ~AbstractAlgorithm();

        // Function operator that runs this algorithm
        virtual void operator()() = 0;

        // User friendly name of the algorithm
        virtual std::string get_name() = 0;

    protected:
        // Board data reference
        BoardWrapper& board;

        // Result container reference
        SlotSet& results;

    private:
};

} // namespace algorithm
} // namespace core
} // namespace sudoku

#endif // ABSTRACTALGORITHM_H
