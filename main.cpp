#include <iostream>

#include <Board.h>
#include <Logger.h>
#include <Ui.h>

using namespace std;

int main()
{
    AbstractLogger::handle_type logger = Logger::create();

    SudokuBoard::handle_type board = SudokuBoard::create();
    board->set_logger(logger);

    AbstractUi::handle_type ui = Ui::create();
    ui->set_logger(logger);

    auto s = ui->get_initial_values();
    ui->print_sudoku(s);

    return 0;
}
