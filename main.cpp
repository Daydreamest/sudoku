#include <iostream>

#include <Board.h>
#include <Ui.h>

using namespace std;

int main()
{
    SudokuBoard::handle_type board = SudokuBoard::create();
    AbstractUi::handler_type ui = Ui::create();

    auto s = ui->get_initial_values();
    ui->print_sudoku(s);

    return 0;
}
