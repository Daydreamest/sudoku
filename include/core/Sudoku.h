#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <functional>
#include <memory>
#include <vector>

#include <AbstractData.h>
#include <Field.h>
#include <LoggerInterface.h>

class Sudoku : public LoggerInterface
{
    public:

        using handle_type = std::shared_ptr<Sudoku>;

        static handle_type create();

        virtual ~Sudoku();

        void set_data(const AbstractData::handle_type d);
        const AbstractData::handle_type get_data() const;

        void set_value(const size_t x, const size_t y, const Value val);

        void solve();

        void TEST();

    protected:
        Sudoku();

    private:
        FieldBoard board;

        Field::handle_type get_field(const size_t x, const size_t y) const;
        FieldRow get_row(const size_t y) const;
        FieldColumn get_column(const size_t x) const;
        FieldTile get_tile(const size_t index) const;
        FieldTile get_tile(const size_t x, const size_t y) const;

        const FieldRow create_empty_row() const;
        const FieldBoard create_empty_array() const;

        void log_field(const size_t x, const size_t y); //TODO shoud be const

        std::vector<std::function<void(Sudoku&)>> algorithms;

        void algorithm_fields_with_single_possible_value();
        void algorithm_only_feasible_place_in_a_row();
        void algorithm_only_feasible_place_in_a_column();
};

#endif // SUDOKUBOARD_H
