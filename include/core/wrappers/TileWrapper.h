#ifndef TILEWRAPPER_H
#define TILEWRAPPER_H

#include <memory>

#include <AbstractWrapper.h>
#include <Field.h>
#include <Position.h>

namespace sudoku {
namespace core {

class TileWrapper : public AbstractWrapper
{
    public:
        // Handle type definition
        using handle_type = std::unique_ptr<TileWrapper>;

        // Building method
        static handle_type create(const FieldTile tile, const size_t id);

        // Destructor
        virtual ~TileWrapper();

    protected:
        // Constructor
        TileWrapper(const FieldTile tile, const size_t id);

        // AbstractWrapper::get_field
        virtual Field::handle_type get_field(const size_t i) const override;

        // AbstractWrapper::get_global_position
        virtual Position get_global_position(const size_t i) const override;

    private:
        // Tile data
        FieldTile data;
};

} // namespace core
} // namespace sudoku

#endif // TILEWRAPPER_H
