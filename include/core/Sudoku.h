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

class Sudoku
{
    public:

        using handle_type = std::shared_ptr<Sudoku>;

        static handle_type create();

        virtual ~Sudoku();

        void set_data(const AbstractData::handle_type d);
        const AbstractData::handle_type get_data();

        void set_value(const Slot slot);

        bool solve_step();

        bool is_solved() const;

        void TEST();

    protected:
        Sudoku();

    private:
        BoardWrapper board;

        AlgorithmContainer algorithms2;

        std::vector<std::function<void(Sudoku&)>> algorithms;

//        void algorithm_fields_with_single_possible_value();
//        void algorithm_only_feasible_place_in_a_row();
//        void algorithm_only_feasible_place_in_a_column();
        void algorithm_only_feasible_place_in_a_tile();

        SlotSet found_fields;
};

#endif // SUDOKUBOARD_H
