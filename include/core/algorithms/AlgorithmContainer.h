#ifndef ALGORITHMCONTAINER_H
#define ALGORITHMCONTAINER_H

#include <memory>
#include <vector>

#include <AbstractAlgorithm.h>
#include <BoardWrapper.h>

namespace sudoku {
namespace core {
namespace algorithm {

class AlgorithmContainer
{
    public:
        // Handle type definition
        using handle_type = std::shared_ptr<AlgorithmContainer>;

        // Constructor
        AlgorithmContainer();

        // Destructor
        virtual ~AlgorithmContainer();

        // Initialize this cintainer with all available algorithms
        void initialize(BoardWrapper& brd, SlotSet& res);

        // Run all initialized algorithms
        void run();

    protected:

    private:
        // Add an algorithm to the storage
        void add(AbstractAlgorithm::handle_type algo);

        // Algorithm storage object
        std::vector<AbstractAlgorithm::handle_type> algorithms;
};

} // namespace algorithm
} // namespace core
} // namespace sudoku

#endif // ALGORITHMCONTAINER_H
