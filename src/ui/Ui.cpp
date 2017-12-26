#include "Ui.h"

#include <iostream>

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
    for(int i = 0; i < 9; i++) {
        auto row = (*s)[i];
        for(auto value : row) {
            std::cout << "." << value << ".";
        }
        std::cout << std::endl;
    }
}
