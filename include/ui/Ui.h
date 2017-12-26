#ifndef UI_H
#define UI_H

#include <Initializer.h>
#include <Logger.h>
#include <SudokuData.h>


class Ui
{
    public:
        Ui();
        virtual ~Ui();

        // Get starting data of the sudoku
        AbstractSudokuData_Pointer get_initial_values();

        void print_sudoku(const AbstractSudokuData_Pointer s);

    protected:

    private:
        Initializer init;
        Logger logger;
};

#endif // UI_H
