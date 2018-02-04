#ifndef ALGORITHMCOLUMNS_H
#define ALGORITHMCOLUMNS_H

#include <AbstractAlgorithm.h>

namespace sudoku {
namespace core {
namespace algorithm {

class AlgorithmColumns : public AbstractAlgorithm
{
    public:
        // Handle type definition
        using handle_type = std::shared_ptr<AlgorithmColumns>;

        // Building method
        static handle_type create(BoardWrapper& brd, SlotSet& res);

        // Destructor
        virtual ~AlgorithmColumns();

        // AbstractAlgorithm::operator()
        virtual void operator()();

        // AbstractAlgorithm::getName
        virtual std::string get_name();

    protected:
        // Constructor
        AlgorithmColumns(BoardWrapper& brd, SlotSet& res);

    private:
};

} // namespace algorithm
} // namespace core
} // namespace sudoku

#endif // ALGORITHMCOLUMNS_H
