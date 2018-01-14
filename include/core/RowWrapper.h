#ifndef ROWWRAPPER_H
#define ROWWRAPPER_H

#include <memory>

#include <Field.h>

class RowWrapper
{
    public:
        using handle_type = std::unique_ptr<RowWrapper>;

        static handle_type create(const FieldRow row);

        virtual ~RowWrapper();

        bool is_solved() const;

        bool contains(const Value val) const;

        size_t possible_places_for(const Value val) const;

        size_t first_acceptabe_position_for(const Value val) const;

    protected:
        RowWrapper(const FieldRow row);

    private:
        FieldRow data;
};

#endif // ROWWRAPPER_H
