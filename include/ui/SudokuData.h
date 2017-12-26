#ifndef SUDOKUDATA_H
#define SUDOKUDATA_H

#include <array>

#include <AbstractSudokuData.h>
#include <Matrix.h>

class SudokuData : public AbstractSudokuData
{
    public:
        SudokuData();
        virtual ~SudokuData();

        virtual std::array<char, 9> operator[] (int x) override;

        void set_value(const size_t x, const size_t y, const char value);

        void reset();

    protected:

    private:
        Matrix<char, 9, 9> data;

        const std::array<char, 9> create_empty_row() const;
        const Matrix<char, 9, 9> create_empty_array() const;
};

#endif // SUDOKUDATA_H
