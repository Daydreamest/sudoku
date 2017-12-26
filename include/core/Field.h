#ifndef FIELD_H
#define FIELD_H

#include <set>

#include <Values.h>

class Field
{
    public:
        Field();
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

    private:
        SudokuValue field_value;
        std::set<SudokuValue> possible_values;
};

#endif // FIELD_H
