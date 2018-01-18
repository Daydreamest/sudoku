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

        virtual bool is_solved() const override;

        virtual bool contains(const Value val) const override;

        virtual size_t possible_places_for(const Value val) const override;

        virtual Position first_position_for(const Value val) const override;

        virtual void sanitize(const Value val) override;

    protected:
        TileWrapper(const FieldTile tile, const size_t id);

    private:
        FieldTile data;

        Position get_global_position(const Position pos) const;
};

#endif // TILEWRAPPER_H
