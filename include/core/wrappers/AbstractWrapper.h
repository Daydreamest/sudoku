#ifndef ABSTRACTWRAPPER_H
#define ABSTRACTWRAPPER_H

#include <cstddef>
#include <memory>

#include <Field.h>
#include <Position.h>
#include <Values.h>

namespace sudoku {
namespace core {

class AbstractWrapper
{
    public:
        // Handle type definition
        using handle_type = std::unique_ptr<AbstractWrapper>;

        // Constructor
        AbstractWrapper(const size_t id, const size_t max_index);

        // Destructor
        virtual ~AbstractWrapper();

        // Check if his element is solved
        bool is_solved() const;

        // Check if this elemnt contains the given value
        bool contains(const Value val) const;

        // Check how many possible places in this element are there for the given value
        size_t possible_places_for(const Value val) const;

        // Retrun first available position for the given value
        Position first_position_for(const Value val) const;

        // Make sure that no fields in this element can possibly be this value
        void sanitize(const Value val);

    protected:
        // ID of this element
        const size_t ID;

        // Maximum index value of this element
        const size_t MAX_INDEX;

        // Get field from this element of the given index
        virtual Field::handle_type get_field(const size_t i) const = 0;

        // Get global sudoku position of the element under given index
        virtual Position get_global_position(const size_t i) const = 0;

    private:
};

} // namespace core
} // namespace sudoku

#endif // ABSTRACTWRAPPER_H
