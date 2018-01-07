#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <memory>

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

        bool is_row_set(const size_t y) const;
        bool row_contains(const size_t y, const Value val) const;
};

#endif // SUDOKUBOARD_H
