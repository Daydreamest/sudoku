#ifndef FIELD_H
#define FIELD_H

#include <memory>
#include <string>

#include <FieldPossibilities.h>
#include <Matrix.h>
#include <Values.h>

namespace sudoku {
namespace core {

class Field
{
    public:
        // Handle definition
        using handle_type = std::shared_ptr<Field>;

        // Building method
        static handle_type create();

        // Default destructor
        virtual ~Field();

        // Reset the field to default empty state
        void reset();

        // Set a specific value to the field
        void set_value(const Value v);

        // Read the current field value
        const Value get_value() const;

        // Check if this field has a set value already
        const bool is_set() const;

        // Check if the field can have a specific value
        const bool can_be(const Value v) const;

        // Mark that this field can't have this value
        void remove_possibility(const Value v);

        // Create string info about this field
        const std::string to_string() const;

        // Get the number of possible value options for this field
        const size_t get_number_of_possibilities() const;

        // Check if this field has only one option and can be set
        // Returns the unique value that can be set in this field or Undefined
        const Value can_be_set() const;

        // Check if this field is set to the given value
        const bool is_set_to(const Value v) const;

    protected:
        // Default constructor
        Field();

    private:
        // Current field value
        Value field_value;

        // A list of possible values that this field may have
        FieldPossibilities::handle_type possible_values;
};

using FieldBoard = Table<Field::handle_type>;
using FieldColumn = Column<Field::handle_type>;
using FieldRow = Row<Field::handle_type>;
using FieldTile = Tile<Field::handle_type>;

} // namespace core
} // namespace sudoku

#endif // FIELD_H
