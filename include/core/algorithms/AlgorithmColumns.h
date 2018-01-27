#ifndef ALGORITHMCOLUMNS_H
#define ALGORITHMCOLUMNS_H

#include <AbstractAlgorithm.h>

namespace sudoku {
namespace core {

class AlgorithmColumns : public AbstractAlgorithm
{
    public:
        using handle_type = std::shared_ptr<AlgorithmColumns>;

        static handle_type create(BoardWrapper& brd, SlotSet& res);
        virtual ~AlgorithmColumns();

        virtual void operator()();

        virtual std::string get_name();

    protected:
        AlgorithmColumns(BoardWrapper& brd, SlotSet& res);

    private:
};

} // namespace core
} // namespace sudoku

#endif // ALGORITHMCOLUMNS_H
