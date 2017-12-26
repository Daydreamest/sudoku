#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <Matrix.h>

class SudokuBoard
{
    public:
        SudokuBoard();
        virtual ~SudokuBoard();

    protected:

    private:

        // TODO set to fields
        Matrix<int, 3, 3> data;
};

#endif // SUDOKUBOARD_H
