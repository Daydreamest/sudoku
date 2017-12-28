#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

#include <memory>

#include <SudokuData.h>

class AbstractUi
{
    public:

        using handler_type = std::shared_ptr<AbstractUi>;

        virtual ~AbstractUi() {};

        // Get starting data of the sudoku
        virtual AbstractSudokuData::handler_type get_initial_values() = 0;

        virtual void print_sudoku(const AbstractSudokuData::handler_type s) = 0;

    protected:
        AbstractUi() {};

    private:
};

#endif // ABSTRACTUI_H
