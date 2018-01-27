#ifndef ALGORITHMROWS_H
#define ALGORITHMROWS_H

#include <AbstractAlgorithm.h>

namespace sudoku {
namespace core {

class AlgorithmRows : public AbstractAlgorithm
{
    public:
        using handle_type = std::shared_ptr<AlgorithmRows>;

        static handle_type create(BoardWrapper& brd, SlotSet& res);

        virtual ~AlgorithmRows();

        virtual void operator()();

        virtual std::string get_name();

    protected:
        AlgorithmRows(BoardWrapper& brd, SlotSet& res);

    private:
};

} // namespace core
} // namespace sudoku

#endif // ALGORITHMROWS_H
