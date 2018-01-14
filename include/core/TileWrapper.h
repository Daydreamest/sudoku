#ifndef TILEWRAPPER_H
#define TILEWRAPPER_H

#include <memory>

#include <Field.h>
#include <Position.h>

class TileWrapper
{
    public:
        using handle_type = std::unique_ptr<TileWrapper>;

        static handle_type create(const FieldTile tile);

        virtual ~TileWrapper();

        bool is_solved() const;

        bool contains(const Value val) const;

        size_t possible_places_for(const Value val) const;

        Position first_acceptabe_position_for(const Value val) const;

    protected:
        TileWrapper(const FieldTile tile);

    private:
        FieldTile data;
};

#endif // TILEWRAPPER_H
