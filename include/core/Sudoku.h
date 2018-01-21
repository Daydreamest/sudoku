#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <functional>
#include <memory>
#include <vector>

#include <AbstractData.h>
#include <AbstractWrapper.h>
#include <Field.h>
//#include <LoggerInterface.h>
#include <Position.h>
#include <Slot.h>

class Sudoku// : public LoggerInterface
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

        void TEST();

    protected:
        Sudoku();

    private:
        FieldBoard board;

        const FieldRow create_empty_row() const;
        const FieldBoard create_empty_array() const;

        AbstractWrapper::handle_type get_row(const size_t y) const;
        AbstractWrapper::handle_type get_column(const size_t x) const;
        AbstractWrapper::handle_type get_tile(const size_t index) const;
        AbstractWrapper::handle_type get_tile(const Position pos) const;

        //TODO remove
        void log_field(const size_t x, const size_t y); //TODO shoud be const

        std::vector<std::function<void(Sudoku&)>> algorithms;

        void algorithm_fields_with_single_possible_value();
        void algorithm_only_feasible_place_in_a_row();
        void algorithm_only_feasible_place_in_a_column();
        void algorithm_only_feasible_place_in_a_tile();

        SlotSet found_fields;
};

#endif // SUDOKUBOARD_H
