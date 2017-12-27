#ifndef UI_H
#define UI_H

#include <AbstractUi.h>
#include <Initializer.h>
#include <Logger.h>
#include <SudokuData.h>

class Ui : public AbstractUi
{
    public:
        Ui();
        virtual ~Ui();

        // Get starting data of the sudoku
        virtual AbstractSudokuData_Pointer get_initial_values() override;

        virtual void print_sudoku(const AbstractSudokuData_Pointer s) override;

    protected:

    private:
        Initializer init;
        Logger logger;
};

#endif // UI_H
