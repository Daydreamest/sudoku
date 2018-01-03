#include "Ui.h"

#include <iostream>

Ui::Ui() : init(Initializer::create())
{
    //ctor
}

Ui::~Ui()
{
    //dtor
}

AbstractData::handle_type Ui::get_initial_values()
{
    return init->get();
}

void Ui::print_sudoku(const AbstractData::handle_type s)
{
    std::cout << "  ----------- ----------- -----------" << std::endl;
    int v_rule = 1;

    for(int x = 0; x < 9; x++) {
        int h_rule = 1;

        std::cout << " | ";

        for (int y = 0; y < 9; y++) {
            std::cout << " " << s->get_value(x, y) << " ";
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

    std::cout << "Ui::print (1,2) = " << s->get_value(1, 2) << std::endl;
}

Ui::handle_type Ui::create()
{
    return handle_type(new Ui);
}

