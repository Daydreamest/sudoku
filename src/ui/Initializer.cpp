#include "Initializer.h"

#include <fstream>
#include <iostream>

#include <Position.h>
#include <UiData.h>

namespace sudoku {
namespace ui {

Initializer::Initializer()
{
    //ctor
}

Initializer::~Initializer()
{
    //dtor
}

AbstractData::handle_type Initializer::get()
{
    UiData::handle_type data = UiData::create();

    std::ifstream infile("input.txt");

    if (!infile.good()) {
        std::cout << "File bad" << std::endl;
        return data;
    }

    std::string line;
    size_t y = 0;
    while (std::getline(infile, line)) {
        for (size_t x = 0; x < 9; x++) {
            data->set_value(Position(x, y), line[x]);
        }
        y++;
    }

    infile.close();
    return data;
}

Initializer::handle_type Initializer::create()
{
    return handle_type(new Initializer);
}

} //namespace ui
} // namespace sudoku
