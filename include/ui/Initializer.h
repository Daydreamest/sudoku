#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <memory>

#include <SudokuData.h>

class Initializer
{
    public:
        Initializer();
        virtual ~Initializer();

        SudokuData_Pointer get();

    protected:

    private:
};

#endif // INITIALIZER_H
