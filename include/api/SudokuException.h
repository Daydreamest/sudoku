#ifndef SUDOKUEXCEPTION_H
#define SUDOKUEXCEPTION_H

#include <exception>
#include <string>

namespace sudoku {

class SudokuException : public std::exception
{
    public:
        // Constructor
        SudokuException() : message("Generic sudoku error") {};

        // Destructor
        virtual ~SudokuException() {};

        // Exception details
        virtual const char* what() const throw() {
            return message.c_str();
        }

    protected:
        // Error message
        std::string message;

    private:
};

} // namespace sudoku

#endif // SUDOKUEXCEPTION_H
