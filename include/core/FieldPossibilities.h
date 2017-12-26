#ifndef FIELDPOSSIBILITIES_H
#define FIELDPOSSIBILITIES_H

#include <set>

#include <Values.h>

class FieldPossibilities
{
    public:
        // Default constructor
        FieldPossibilities();

        // Default destructor
        virtual ~FieldPossibilities();

        // Remove all possible values from the possibility list
        void clear();

        // Reset the list to starting state (all values are permitted)
        void reset();

        // Remove the given value from the possibilities
        void remove(const SudokuValue v);

        // Check if the list contains the given value
        bool contains(const SudokuValue v) const;

    protected:

    private:

        // A list of possible values that this field may have
        std::set<SudokuValue> possible_values;
};

#endif // FIELDPOSSIBILITIES_H
