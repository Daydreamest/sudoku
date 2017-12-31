#include "Main.h"

#include <Sudoku.h>
#include <Logger.h>
#include <Ui.h>

Main::Main() : sudoku(nullptr), ui(nullptr)
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

    result->sudoku = Sudoku::create();
    result->sudoku->set_logger(logger);

    return std::move(result);
}

void Main::run()
{
    sudoku->set_data(ui->get_initial_values());

    ui->print_sudoku(sudoku->get_data());

    sudoku->TEST();
}
