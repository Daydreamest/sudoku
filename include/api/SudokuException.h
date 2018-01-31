#ifndef SUDOKUEXCEPTION_H
#define SUDOKUEXCEPTION_H

#include <exception>

namespace sudoku {

class SudokuException : public std::exception
{
    public:
        // Constructor
        SudokuException() {};

        // Destructor
        virtual ~SudokuException() {};

        // Exception details
        virtual const char* what() const throw() {
            return "Generic sudoku exception";
        }

    protected:

    private:
};

} // namespace sudoku

#endif // SUDOKUEXCEPTION_H
