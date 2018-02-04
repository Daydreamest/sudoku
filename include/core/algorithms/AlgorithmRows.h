#ifndef ALGORITHMROWS_H
#define ALGORITHMROWS_H

#include <AbstractAlgorithm.h>

namespace sudoku {
namespace core {
namespace algorithm {

class AlgorithmRows : public AbstractAlgorithm
{
    public:
        // Handle type definition
        using handle_type = std::shared_ptr<AlgorithmRows>;

        // Building method
        static handle_type create(BoardWrapper& brd, SlotSet& res);

        // Destructor
        virtual ~AlgorithmRows();

        // AbstractAlgorithm::operator()
        virtual void operator()();

        // AbstractAlgorithm::getName
        virtual std::string get_name();

    protected:
        // Constructor
        AlgorithmRows(BoardWrapper& brd, SlotSet& res);

    private:
};

} // namespace algorithm
} // namespace core
} // namespace sudoku

#endif // ALGORITHMROWS_H
