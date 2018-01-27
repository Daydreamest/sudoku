#include "ColumnWrapper.h"

#include <Consts.h>

namespace sudoku {
namespace core {

ColumnWrapper::ColumnWrapper(const FieldColumn col, const size_t id): AbstractWrapper(id, consts::COLUMN_MAX), data(col)
{
    //ctor
}

ColumnWrapper::~ColumnWrapper()
{
    //dtor
}

ColumnWrapper::handle_type ColumnWrapper::create(const FieldColumn col, const size_t id)
{
    return handle_type(new ColumnWrapper(col, id));
}

Field::handle_type ColumnWrapper::get_field(const size_t i) const
{
    return data[i];
}

Position ColumnWrapper::get_global_position(const size_t i) const
{
    return Position(ID, i);
}

} // namespace core
} // namespace sudoku
