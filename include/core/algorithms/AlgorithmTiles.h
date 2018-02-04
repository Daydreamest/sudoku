#ifndef ALGORITHMTILES_H
#define ALGORITHMTILES_H

#include <AbstractAlgorithm.h>

namespace sudoku {
namespace core {
namespace algorithm {

class AlgorithmTiles : public AbstractAlgorithm
{
    public:
        // Handle type definition
        using handle_type = std::shared_ptr<AlgorithmTiles>;

        // Building method
        static handle_type create(BoardWrapper& brd, SlotSet& res);

        // Destructor
        virtual ~AlgorithmTiles();

        // AbstractAlgorithm::operator()
        virtual void operator()();

        // AbstractAlgorithm::getName
        virtual std::string get_name();

    protected:
        // Constructor
        AlgorithmTiles(BoardWrapper& brd, SlotSet& res);

    private:
};

} // namespace algorithm
} // namespace core
} // namespace sudoku

#endif // ALGORITHMTILES_H
