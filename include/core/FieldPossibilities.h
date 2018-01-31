#ifndef FIELDPOSSIBILITIES_H
#define FIELDPOSSIBILITIES_H

#include <memory>
#include <set>

#include <Values.h>

namespace sudoku {
namespace core {

class FieldPossibilities
{
    public:
        // Handle definition
        using handle_type = std::unique_ptr<FieldPossibilities>;

        // Building method
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
        const bool contains(const Value v) const;

        // Get the number of possible values
        const size_t get_number_of_possibilities() const;

        // Get the only available value left, or Undefined if there are more/less than one
        const Value get_unique_possibility() const;

    protected:
        // Default constructor
        FieldPossibilities();

    private:
        // A list of possible values that this field may have
        std::set<Value> possible_values;
};

} // namespace core
} // namespace sudoku

#endif // FIELDPOSSIBILITIES_H
