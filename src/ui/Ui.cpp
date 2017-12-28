#include "Ui.h"

#include <iostream>

Ui::Ui() : init(Initializer::create()), logger(Logger::create())
{
    //ctor
}

Ui::~Ui()
{
    //dtor
}

AbstractSudokuData::handler_type Ui::get_initial_values()
{
    return init->get();
}

void Ui::print_sudoku(const AbstractSudokuData::handler_type s)
{
    std::cout << "  ----------- ----------- -----------" << std::endl;
    int v_rule = 1;
    for(int i = 0; i < 9; i++) {
        auto row = (*s)[i];
        int h_rule = 1;
        std::cout << " | ";
        for(auto value : row) {
            std::cout << " " << value << " ";
            if (!(h_rule % 3)) {
                std::cout << " | ";
            }
            h_rule++;
        }
        std::cout << std::endl;

        if (!(v_rule % 3)) {
            std::cout << "  ----------- ----------- -----------" << std::endl;
        }
            v_rule++;
    }
}

Ui::handle_type Ui::create()
{
    return handle_type(new Ui);

    // TODO needs specific allocator for protected constructor
//    return std::make_shared<Ui>();
}

