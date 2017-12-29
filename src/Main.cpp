#include "Main.h"

#include <Board.h>
#include <Logger.h>
#include <Ui.h>

Main::Main() : logger(nullptr), board(nullptr), ui(nullptr)
{
    //ctor
}

Main::~Main()
{
    //dtor
}

Main::handle_type Main::create()
{
    return handle_type(new Main);
}

void Main::run()
{
    auto s = ui->get_initial_values();
    ui->print_sudoku(s);
}

void Main::initialize()
{
    logger = Logger::create();

    board = SudokuBoard::create();
    board->set_logger(logger);

    ui = Ui::create();
    ui->set_logger(logger);
}
