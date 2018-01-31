#ifndef ROWWRAPPER_H
#define ROWWRAPPER_H

#include <memory>

#include <AbstractWrapper.h>
#include <Field.h>
#include <Position.h>

namespace sudoku {
namespace core {

class RowWrapper : public AbstractWrapper
{
    public:
        // Handle type definition
        using handle_type = std::unique_ptr<RowWrapper>;

        // Building method
        static handle_type create(const FieldRow row, const size_t id);

        // Destructor
        virtual ~RowWrapper();

    protected:
        // Constructor
        RowWrapper(const FieldRow row, const size_t id);

        // AbstractWrapper::get_field
        virtual Field::handle_type get_field(const size_t i) const override;

        // AbstractWrapper::get_global_position
        virtual Position get_global_position(const size_t i) const override;

    private:
        // Row data
        FieldRow data;
};

} // namespace core
} // namespace sudoku

#endif // ROWWRAPPER_H
