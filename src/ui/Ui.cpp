#include "Ui.h"

Ui::Ui() : init(Initializer()), logger(Logger())
{
    //ctor
}

Ui::~Ui()
{
    //dtor
}

AbstractSudokuData_Pointer Ui::get_initial_values()
{
    return init.get();
}

void Ui::print_sudoku(const AbstractSudokuData_Pointer s)
{

}
