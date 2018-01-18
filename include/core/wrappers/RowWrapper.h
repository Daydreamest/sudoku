#ifndef ROWWRAPPER_H
#define ROWWRAPPER_H

#include <memory>

#include <AbstractWrapper.h>
#include <Field.h>

class RowWrapper : public AbstractWrapper
{
    public:
        using handle_type = std::unique_ptr<RowWrapper>;

        static handle_type create(const FieldRow row, const size_t id);

        virtual ~RowWrapper();

        virtual bool is_solved() const override;

        virtual bool contains(const Value val) const override;

        virtual size_t possible_places_for(const Value val) const override;

        virtual Position first_position_for(const Value val) const override;

        virtual void sanitize(const Value val) override;

    protected:
        RowWrapper(const FieldRow row, const size_t id);

    private:
        FieldRow data;
};

#endif // ROWWRAPPER_H
