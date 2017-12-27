#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

#include <SudokuData.h>

class AbstractUi
{
    public:

        virtual ~AbstractUi() {};

        // Get starting data of the sudoku
        virtual AbstractSudokuData_Pointer get_initial_values() = 0;

        virtual void print_sudoku(const AbstractSudokuData_Pointer s) = 0;

    protected:

    private:
};

#endif // ABSTRACTUI_H
