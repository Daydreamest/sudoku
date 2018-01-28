#ifndef SUDOKUEXCEPTION_H
#define SUDOKUEXCEPTION_H

#include <exception>

class SudokuException : public std::exception
{
    public:
        SudokuException() {};
        virtual ~SudokuException() {};

        virtual const char* what() const throw() {
            return "Generic sudoku exception";
        }

    protected:

    private:
};

#endif // SUDOKUEXCEPTION_H
