#ifndef FIELD_H
#define FIELD_H

#include <memory>

#include <FieldPossibilities.h>
#include <Values.h>

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
        void set_value(const SudokuValue v);

        // Read the current field value
        SudokuValue get_value() const;

        // Check if this field has a set balue already
        bool is_set() const;

        // Check if the field can have a specific value
        bool can_be(const SudokuValue v) const;

    protected:
        // Default constructor
        Field();

    private:

        // Current field value
        SudokuValue field_value;

        // A list of possible values that this field may have
        FieldPossibilities::handle_type possible_values;
};

#endif // FIELD_H
