#ifndef COREDATA_H
#define COREDATA_H

#include <AbstractData.h>

#include <Matrix.h>
#include <Position.h>
#include <Slot.h>
#include <Values.h>

namespace sudoku {

class CoreData : public AbstractData
{
    public:
        using handle_type = std::shared_ptr<CoreData>;

        static handle_type create();
        virtual ~CoreData();

        // TODO should return const char
        virtual char get_value(const Position pos) const override;

        void set_value(const Slot slot);

    protected:
        CoreData();

    private:
        Table<char> data;

        const Table<char> create_empty_array() const;
};

} // namespace sudoku

#endif // COREDATA_H
