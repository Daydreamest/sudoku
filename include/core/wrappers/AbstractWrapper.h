#ifndef ABSTRACTWRAPPER_H
#define ABSTRACTWRAPPER_H

#include <cstddef>
#include <memory>

#include <Field.h>
#include <Position.h>
#include <Values.h>

namespace sudoku {

class AbstractWrapper
{
    public:
        using handle_type = std::unique_ptr<AbstractWrapper>;
        explicit AbstractWrapper(const size_t id, const size_t max_index);
        virtual ~AbstractWrapper();

        bool is_solved() const;

        bool contains(const Value val) const;

        size_t possible_places_for(const Value val) const;

        Position first_position_for(const Value val) const;

        void sanitize(const Value val);

    protected:
        const size_t ID;
        const size_t MAX_INDEX;

        virtual Field::handle_type get_field(const size_t i) const = 0;

        virtual Position get_global_position(const size_t i) const = 0;

    private:
};

} // namespace sudoku

#endif // ABSTRACTWRAPPER_H
