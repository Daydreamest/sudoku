#ifndef SUDOKUDATA_H
#define SUDOKUDATA_H

#include <memory>

#include <AbstractSudokuData.h>
#include <Matrix.h>

class SudokuData : public AbstractSudokuData
{
    public:
        using handle_type = std::shared_ptr<SudokuData>;

        static handle_type create();
        virtual ~SudokuData();

        virtual SudokuRow<char> operator[] (int x) override;

        void set_value(const size_t x, const size_t y, const char value);

        virtual char get_value(const size_t x, const size_t y) const override;

        void reset();

    protected:
        SudokuData();

    private:
        SudokuTable<char> data;

        const SudokuRow<char> create_empty_row() const;
        const SudokuTable<char> create_empty_array() const;
};

#endif // SUDOKUDATA_H
