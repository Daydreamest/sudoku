#ifndef FIELD_H
#define FIELD_H

#include <memory>
#include <string> // TODO not needed in final version

#include <FieldPossibilities.h>
#include <Matrix.h>
#include <Values.h>

namespace sudoku {

class Field
{
    public:
        using handle_type = std::shared_ptr<Field>;

        static handle_type create();

        // Default destructor
        virtual ~Field();

        // Reset the field to default empty state
        void reset();

        // Set a specific value to the field
        void set_value(const Value v);

        // Read the current field value
        Value get_value() const;

        // Check if this field has a set value already
        bool is_set() const;

        // Check if the field can have a specific value
        bool can_be(const Value v) const;

        // Mark that this field can't have this value
        void remove_possibility(const Value v);

        // Create string info about this field
        const std::string to_string() const;

        // Get the number of possible value options for this field
        size_t get_number_of_possibilities() const;

        // Check if this field has only one option and can be set
        // Returns the unique value that can be set in this field or Undefined
        Value can_be_set() const;

        bool is_set_to(const Value v) const;

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

} // namespace sudoku

#endif // FIELD_H
