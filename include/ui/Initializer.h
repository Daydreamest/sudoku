#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <SudokuData.h>

class Initializer
{
    public:
        Initializer();
        virtual ~Initializer();

        SudokuData get();

    protected:

    private:
};

#endif // INITIALIZER_H
