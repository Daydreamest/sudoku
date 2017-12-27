#ifndef SUDOKUDATA_H
#define SUDOKUDATA_H

#include <array>
#include <memory>

#include <AbstractSudokuData.h>
#include <Matrix.h>

class SudokuData : public AbstractSudokuData
{
    public:
        SudokuData();
        virtual ~SudokuData();

        virtual SudokuRow<char> operator[] (int x) override;

        void set_value(const size_t x, const size_t y, const char value);

        void reset();

    protected:

    private:
        SudokuTable<char> data;

        const SudokuRow<char> create_empty_row() const;
        const SudokuTable<char> create_empty_array() const;
};

using SudokuData_Pointer = std::shared_ptr<SudokuData>;

#endif // SUDOKUDATA_H
