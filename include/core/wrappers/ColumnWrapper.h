#ifndef COLUMNWRAPPER_H
#define COLUMNWRAPPER_H

#include <memory>

#include <AbstractWrapper.h>
#include <Field.h>
#include <Position.h>

namespace sudoku {
namespace core {

class ColumnWrapper : public AbstractWrapper
{
    public:
        // Handle type definition
        using handle_type = std::unique_ptr<ColumnWrapper>;

        // Building method
        static handle_type create(const FieldColumn col, const size_t id);

        // Destructor
        virtual ~ColumnWrapper();

    protected:
        // Constructor
        ColumnWrapper(const FieldColumn col, const size_t id);

        // AbstractWrapper::get_field
        virtual Field::handle_type get_field(const size_t i) const override;

        // AbstractWrapper::get_global_position
        virtual Position get_global_position(const size_t i) const override;

    private:
        // Row data
        FieldColumn data;
};

} // namespace core
} // namespace sudoku

#endif // COLUMNWRAPPER_H
