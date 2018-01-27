#ifndef COLUMNWRAPPER_H
#define COLUMNWRAPPER_H

#include <memory>

#include <AbstractWrapper.h>
#include <Field.h>

namespace sudoku {
namespace core {

class ColumnWrapper : public AbstractWrapper
{
    public:
        using handle_type = std::unique_ptr<ColumnWrapper>;

        static handle_type create(const FieldColumn col, const size_t id);

        virtual ~ColumnWrapper();

    protected:
        ColumnWrapper(const FieldColumn col, const size_t id);

        virtual Field::handle_type get_field(const size_t i) const override;

        virtual Position get_global_position(const size_t i) const override;

    private:
        FieldColumn data;
};

} // namespace core
} // namespace sudoku

#endif // COLUMNWRAPPER_H
