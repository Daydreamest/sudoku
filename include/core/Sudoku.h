#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <functional>
#include <memory>
#include <vector>

#include <AbstractData.h>
#include <AbstractWrapper.h>
#include <AlgorithmContainer.h>
#include <BoardWrapper.h>
#include <Field.h>
#include <Position.h>
#include <Slot.h>

namespace sudoku {
namespace core {

class Sudoku
{
    public:

        using handle_type = std::shared_ptr<Sudoku>;

        static handle_type create();

        virtual ~Sudoku();

        void set_data(const AbstractData::handle_type d);
        const AbstractData::handle_type get_data() const;

        void set_value(const Slot slot);

        bool solve_step();

        bool is_solved() const;

    protected:
        Sudoku();

    private:
        BoardWrapper board;

        algorithm::AlgorithmContainer algorithms;

        SlotSet found_fields;
};

} // namespace core
} // namespace sudoku

#endif // SUDOKUBOARD_H
