#ifndef ALGORITHMFIELDS_H
#define ALGORITHMFIELDS_H

#include <AbstractAlgorithm.h>

namespace sudoku {
namespace core {
namespace algorithm {

class AlgorithmFields : public AbstractAlgorithm
{
    public:
        // Handle type definition
        using handle_type = std::shared_ptr<AlgorithmFields>;

        // Building method
        static handle_type create(BoardWrapper& brd, SlotSet& res);

        // Destructor
        virtual ~AlgorithmFields();

        // AbstractAlgorithm::operator()
        virtual void operator()();

        // AbstractAlgorithm::getName
        virtual std::string get_name();

    protected:
        // Constructor
        AlgorithmFields(BoardWrapper& brd, SlotSet& res);

    private:
};

} // namespace algorithm
} // namespace core
} // namespace sudoku

#endif // ALGORITHMFIELDS_H
