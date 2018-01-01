#ifndef FIELDPOSSIBILITIES_H
#define FIELDPOSSIBILITIES_H

#include <memory>
#include <set>

#include <Values.h>

class FieldPossibilities
{
    public:

        using handle_type = std::shared_ptr<FieldPossibilities>;

        static handle_type create();

        // Default destructor
        virtual ~FieldPossibilities();

        // Remove all possible values from the possibility list
        void clear();

        // Reset the list to starting state (all values are permitted)
        void reset();

        // Remove the given value from the possibilities
        void remove(const Value v);

        // Check if the list contains the given value
        bool contains(const Value v) const;

    protected:
        // Default constructor
        FieldPossibilities();

    private:

        // A list of possible values that this field may have
        std::set<Value> possible_values;
};

#endif // FIELDPOSSIBILITIES_H
