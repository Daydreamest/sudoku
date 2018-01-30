#ifndef COREDATA_H
#define COREDATA_H

#include <AbstractData.h>

#include <Matrix.h>
#include <Position.h>
#include <Slot.h>
#include <Values.h>

namespace sudoku {
namespace core {

class CoreData : public AbstractData
{
    public:
        // Handle type definition
        using handle_type = std::shared_ptr<CoreData>;

        // Building method
        static handle_type create();

        // Destructor
        virtual ~CoreData();

        // AbstractData::get_value
        virtual const char get_value(const Position pos) const override;

        // Value setter for a specific position
        void set_value(const Slot slot);

    protected:
        // Constructor
        CoreData();

    private:
        // Data table
        Table<char> data;

        // Creator of a default, empty data table
        const Table<char> create_empty_array() const;
};

} // namespace core
} // namespace sudoku

#endif // COREDATA_H
