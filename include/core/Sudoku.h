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
        // Handle type definition
        using handle_type = std::shared_ptr<Sudoku>;

        // Building method
        static handle_type create();

        // Destructor
        virtual ~Sudoku();

        // Set this sudoku with the given data
        void set_data(const AbstractData::handle_type d);

        // Create Data object of this sudoku
        const AbstractData::handle_type get_data() const;

        // Make one step to solve the sudoku - go through all the algorithms once
        bool solve_step();

        // Check if sudoku is already solved
        bool is_solved() const;

    protected:
        // Constructor
        Sudoku();

    private:
        // Set a field in the given position to a the given value
        void set_value(const Slot slot);

        // Board data
        BoardWrapper board;

        // Container for all available algorithms
        algorithm::AlgorithmContainer algorithms;

        // Container for fields solved in the current solution step
        SlotSet found_fields;
};

} // namespace core
} // namespace sudoku

#endif // SUDOKUBOARD_H
