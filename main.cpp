#include <iostream>

#include <Board.h>
#include <Ui.h>

using namespace std;

int main()
{
    SudokuBoard board;
    Ui ui;

    auto s = ui.get_initial_values();
    ui.print_sudoku(s);

    return 0;
}
