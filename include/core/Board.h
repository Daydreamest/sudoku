#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <memory>

#include <AbstractSudokuData.h>
#include <Field.h>
#include <Matrix.h>

class SudokuBoard
{
    public:

        using handle_type = std::shared_ptr<SudokuBoard>;

        static handle_type create();

        virtual ~SudokuBoard();

        void set_data(const AbstractSudokuData::handler_type d);

        void set_value(const size_t x, const size_t y, const SudokuValue val);

    protected:
        SudokuBoard();

    private:

        SudokuRow<Field::handle_type> get_row(size_t i) const;
        SudokuColumn<Field::handle_type> get_column(size_t i) const;
        SudokuTile<Field::handle_type> get_tile(size_t i) const;
        SudokuTile<Field::handle_type> get_tile(size_t x, size_t y) const;
        Field::handle_type get_field(size_t x, size_t y) const;

        // TODO set to fields
        SudokuTable<Field::handle_type> data;

        const SudokuRow<Field::handle_type> create_empty_row() const;
        const SudokuTable<Field::handle_type> create_empty_array() const;
};

#endif // SUDOKUBOARD_H
