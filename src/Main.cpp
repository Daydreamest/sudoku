#include "Main.h"

#include <Logger.h>
#include <Sudoku.h>
#include <Ui.h>

#include <SudokuException.h>

namespace sudoku {

ui::Logger log;

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

    // Set the logger
    log.set_log_level(LogLevel_Warning);

    // Create and initialize Ui
    result->ui = ui::Ui::create();

    // Create and initialize Sudoku class
    result->sudoku = core::Sudoku::create();

    return std::move(result);
}

void Main::run()
{
    try {
        sudoku->set_data(ui->get_initial_values());

        ui->print_sudoku(sudoku->get_data());

        bool has_next_step = true;

        while (has_next_step) {
//            ui->print_sudoku(sudoku->get_data());
            has_next_step = sudoku->solve_step();
        }
    } catch (SudokuException& e) {
        log(LogLevel_Error) << e.what() << std::endl;
        return;
    }

    ui->print_sudoku(sudoku->get_data());
//    has_next_step = sudoku->solve_step();
}

} // namespace sudoku
