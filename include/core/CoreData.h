#ifndef COREDATA_H
#define COREDATA_H

#include <AbstractSudokuData.h>

#include <Matrix.h>
#include <Values.h>

class CoreData : public AbstractData
{
    public:
        using handle_type = std::shared_ptr<CoreData>;

        static handle_type create();
        virtual ~CoreData();

        virtual Row<char> operator[] (int x) override;

        // TODO should return const char
        virtual char get_value(const size_t x, const size_t y) const override;

        void set_value(const size_t x, const size_t y, const SudokuValue val);

    protected:
        CoreData();

    private:
        Table<char> data;

        const Row<char> create_empty_row() const;
        const Table<char> create_empty_array() const;

};

#endif // COREDATA_H
