#include "RowWrapper.h"

#include <Consts.h>

namespace sudoku {
namespace core {

RowWrapper::RowWrapper(const FieldRow row, const size_t id) : AbstractWrapper(id, ROW_MAX), data(row)
{
    //ctor
}

RowWrapper::~RowWrapper()
{
    //dtor
}

RowWrapper::handle_type RowWrapper::create(const FieldRow row, const size_t id)
{
    return handle_type(new RowWrapper(row, id));
}

Field::handle_type RowWrapper::get_field(const size_t i) const
{
    return data[i];
}

Position RowWrapper::get_global_position(const size_t i) const
{
    return Position(i, ID);
}

} // namespace core
} // namespace sudoku
