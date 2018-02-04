#include "Ui.h"

#include <iostream>

namespace sudoku {
namespace ui {

Ui::Ui(const std::string input_file_name) : init(Initializer::create(input_file_name))
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

    for(size_t y = 0; y < 9; y++) {
        int h_rule = 1;

        std::cout << " | ";

        for (size_t x = 0; x < 9; x++) {
            std::cout << " " << s->get_value(Position(x, y)) << " ";
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

//    std::cout << std::endl << "Press Enter to continue..." << std::endl;
//    std::cin.ignore();
}

Ui::handle_type Ui::create(const std::string input_file_name)
{
    return handle_type(new Ui(input_file_name));
}

} //namespace ui
} // namespace sudoku
