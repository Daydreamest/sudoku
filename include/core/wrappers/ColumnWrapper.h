#ifndef COLUMNWRAPPER_H
#define COLUMNWRAPPER_H

#include <memory>

#include <Field.h>

class ColumnWrapper
{
    public:
        using handle_type = std::unique_ptr<ColumnWrapper>;

        static handle_type create(const FieldColumn col);

        virtual ~ColumnWrapper();

        bool is_solved() const;

        bool contains(const Value val) const;

        size_t possible_places_for(const Value val) const;

        size_t first_acceptabe_position_for(const Value val) const;

    protected:
        ColumnWrapper(const FieldColumn col);

    private:
        FieldColumn data;
};

#endif // COLUMNWRAPPER_H
