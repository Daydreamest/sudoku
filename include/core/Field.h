#ifndef FIELD_H
#define FIELD_H

#include <memory>

#include <FieldPossibilities.h>
#include <Matrix.h>
#include <Values.h>

class Field
{
    public:
        using handle_type = std::shared_ptr<Field>;

        static handle_type create();

        // Default destructor
        virtual ~Field();

        // Reset the field to default empty state
        void reset();

        // Set a specific value to the field
        void set_value(const Value v);

        // Read the current field value
        Value get_value() const;

        // Check if this field has a set balue already
        bool is_set() const;

        // Check if the field can have a specific value
        bool can_be(const Value v) const;

        // Mark that this field can't have this value
        void remove_possibility(const Value v);

    protected:
        // Default constructor
        Field();

    private:

        // Current field value
        Value field_value;

        // A list of possible values that this field may have
        FieldPossibilities::handle_type possible_values;
};

using FieldBoard = Table<Field::handle_type>;
using FieldColumn = Column<Field::handle_type>;
using FieldRow = Row<Field::handle_type>;
using FieldTile = Tile<Field::handle_type>;

#endif // FIELD_H
