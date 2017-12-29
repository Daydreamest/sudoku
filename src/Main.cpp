#include "Main.h"

#include <Board.h>
#include <Logger.h>
#include <Ui.h>

Main::Main() : board(nullptr), ui(nullptr)
{
    //ctor
}

Main::~Main()
{
    //dtor
}

Main::handle_type Main::create()
{
    handle_type result = std::make_unique<Main>();

    auto logger = Logger::create();

    result->ui = Ui::create();
    result->ui->set_logger(logger);

    result->board = SudokuBoard::create();
    result->board->set_logger(logger);

    return std::move(result);
}

void Main::run()
{
    auto s = ui->get_initial_values();
    ui->print_sudoku(s);

    board->set_data(s);

//    board->set_value(0,0,Value_5);
}
