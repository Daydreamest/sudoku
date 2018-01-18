#ifndef ABSTRACTWRAPPER_H
#define ABSTRACTWRAPPER_H

#include <cstddef>

#include <Position.h>
#include <Values.h>

class AbstractWrapper
{
    public:
        explicit AbstractWrapper(const size_t id);
        virtual ~AbstractWrapper();

        virtual bool is_solved() const = 0;

        virtual bool contains(const Value val) const = 0;

        virtual size_t possible_places_for(const Value val) const = 0;

        virtual Position first_position_for(const Value val) const = 0;

        virtual void sanitize(const Value val) = 0;

    protected:
        size_t index;

    private:
};

#endif // ABSTRACTWRAPPER_H
