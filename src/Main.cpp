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
    result->config.set_log_level(LogLevel_Warning);

    // Set verbosity
    result->config.set_verbosity(false);

    // Create and initialize Ui
    result->ui = ui::Ui::create();

    // Create and initialize Sudoku class
    result->sudoku = core::Sudoku::create();

    return std::move(result);
}

int Main::run()
{
    try {
        // Read starting board
        sudoku->set_data(ui->get_initial_values());

        // Print the staring board
        ui->print_sudoku(sudoku->get_data());

        bool has_next_step = true;

        // Solve the sudoku
        while (has_next_step) {
            has_next_step = sudoku->solve_step();

            // Show every steop of the solution?
            if (config.is_verbose()) {
                ui->print_sudoku(sudoku->get_data());
            }
        }
    } catch (SudokuException& e) {
        log(LogLevel_Error) << e.what() << std::endl;
        return 1;
    }

    // Print the final state of the sudoku
    ui->print_sudoku(sudoku->get_data());

    return 0;
}

} // namespace sudoku
