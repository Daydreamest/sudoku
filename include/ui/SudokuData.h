#ifndef SUDOKUDATA_H
#define SUDOKUDATA_H

#include <memory>

#include <AbstractSudokuData.h>
#include <Matrix.h>

class UiData : public AbstractData
{
    public:
        using handle_type = std::shared_ptr<UiData>;

        static handle_type create();
        virtual ~UiData();

        virtual Row<char> operator[] (int x) override;

        void set_value(const size_t x, const size_t y, const char value);

        virtual char get_value(const size_t x, const size_t y) const override;

        void reset();

    protected:
        UiData();

    private:
        Table<char> data;

        const Row<char> create_empty_row() const;
        const Table<char> create_empty_array() const;
};

#endif // SUDOKUDATA_H
