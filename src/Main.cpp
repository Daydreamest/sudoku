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

    // Create a logger
    auto logger = Logger::create();

    // Create and initialize Ui
    result->ui = Ui::create();
    result->ui->set_logger(logger);

    // Create and initialize Sudoku class
    result->sudoku = Sudoku::create();
    result->sudoku->set_logger(logger);

    return std::move(result);
}

void Main::run()
{
    sudoku->set_data(ui->get_initial_values());

    bool has_next_step = true;

    while (has_next_step) {
        ui->print_sudoku(sudoku->get_data());
        has_next_step = sudoku->solve_step();
    }

    ui->print_sudoku(sudoku->get_data());
}
