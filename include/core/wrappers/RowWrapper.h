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

    protected:
        RowWrapper(const FieldRow row, const size_t id);

        virtual Field::handle_type get_field(const size_t i) const override;

        virtual Position get_global_position(const size_t i) const override;

    private:
        FieldRow data;
};

#endif // ROWWRAPPER_H
