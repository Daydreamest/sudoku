#ifndef TILEWRAPPER_H
#define TILEWRAPPER_H

#include <memory>

#include <AbstractWrapper.h>
#include <Field.h>
#include <Position.h>

class TileWrapper : public AbstractWrapper
{
    public:
        using handle_type = std::unique_ptr<TileWrapper>;

        static handle_type create(const FieldTile tile, const size_t id);

        virtual ~TileWrapper();

    protected:
        TileWrapper(const FieldTile tile, const size_t id);

        virtual Field::handle_type get_field(const size_t i) const override;

        virtual Position get_global_position(const size_t i) const override;

    private:
        FieldTile data;
};

#endif // TILEWRAPPER_H
