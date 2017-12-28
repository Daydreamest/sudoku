#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H

#include <memory>

#include <Matrix.h>

class SudokuBoard
{
    public:

        using handle_type = std::shared_ptr<SudokuBoard>;

        static handle_type create();

        virtual ~SudokuBoard();

    protected:
        SudokuBoard();

    private:

        // TODO set to fields
        SudokuTable<int> data;
};

#endif // SUDOKUBOARD_H
