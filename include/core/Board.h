#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <memory>

#include <AbstractSudokuData.h>
#include <LoggerInterface.h>
#include <Field.h>
#include <Matrix.h>

class Sudoku : public LoggerInterface
{
    public:

        using handle_type = std::shared_ptr<Sudoku>;

        static handle_type create();

        virtual ~Sudoku();

        void set_data(const AbstractData::handle_type d);
        const AbstractData::handle_type get_data() const;

        void set_value(const size_t x, const size_t y, const SudokuValue val);

    protected:
        Sudoku();

    private:
        Table<Field::handle_type> data;

        Field::handle_type get_field(const size_t x, const size_t y) const;
        Row<Field::handle_type> get_row(const size_t i) const;
        Column<Field::handle_type> get_column(const size_t i) const;
        Tile<Field::handle_type> get_tile(const size_t index) const;
        Tile<Field::handle_type> get_tile(const size_t x, const size_t y) const;

        const Row<Field::handle_type> create_empty_row() const;
        const Table<Field::handle_type> create_empty_array() const;
};

#endif // SUDOKUBOARD_H
