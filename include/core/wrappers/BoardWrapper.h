#ifndef BOARDWRAPPER_H
#define BOARDWRAPPER_H

#include <AbstractWrapper.h>
#include <Field.h>
#include <Position.h>
#include <Slot.h>

namespace sudoku {
namespace core {

class BoardWrapper
{
    public:
        // Constructor
        BoardWrapper();

        // Destructor
        virtual ~BoardWrapper();

        // Set a value on the given position
        void set_value(const Slot slot);

        // [] operator for easy iteration
        const FieldColumn& operator[](const size_t x) const;

        // Row extractor
        AbstractWrapper::handle_type get_row(const size_t y) const;

        // Column extractor
        AbstractWrapper::handle_type get_column(const size_t x) const;

        // Tile extractor
        AbstractWrapper::handle_type get_tile(const size_t index) const;

        // Tile extractor
        AbstractWrapper::handle_type get_tile(const Position pos) const;

    private:
        // Board data
        FieldBoard board;

        // Create empty row to fill up the table
        const FieldRow create_empty_row() const;

        // Create an empty table to initialize the board
        const FieldBoard create_empty_array() const;
};

} // namespace core
} // namespace sudoku

#endif // BOARDWRAPPER_H
