#ifndef COLUMNWRAPPER_H
#define COLUMNWRAPPER_H

#include <memory>

#include <AbstractWrapper.h>
#include <Field.h>

class ColumnWrapper : public AbstractWrapper
{
    public:
        using handle_type = std::unique_ptr<ColumnWrapper>;

        static handle_type create(const FieldColumn col, const size_t id);

        virtual ~ColumnWrapper();

        virtual bool is_solved() const override;

        virtual bool contains(const Value val) const override;

        virtual size_t possible_places_for(const Value val) const override;

        virtual Position first_position_for(const Value val) const override;

        virtual void sanitize(const Value val) override;

    protected:
        ColumnWrapper(const FieldColumn col, const size_t id);

    private:
        FieldColumn data;
};

#endif // COLUMNWRAPPER_H
