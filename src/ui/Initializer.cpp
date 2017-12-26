#include "Initializer.h"

Initializer::Initializer()
{
    //ctor
}

Initializer::~Initializer()
{
    //dtor
}

SudokuData_Pointer Initializer::get()
{
    SudokuData_Pointer p = std::make_shared<SudokuData>();
    // TODO fill it up
    return p;
}
