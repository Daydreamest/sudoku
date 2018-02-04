#include "Main.h"

#include <Logger.h>
#include <Sudoku.h>
#include <Ui.h>

#include <SudokuException.h>

namespace sudoku {

// Logger deffinition
ui::Logger log;

Main::Main()
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

    // Set the logging level
    result->config.set_log_level(LogLevel_Warning);

    // Set verbosity
    result->config.set_verbosity(false);

    // Set input data file name
    result->config.set_input_data("input.txt");

    // Create and initialize UI
    result->ui = ui::Ui::create("input.txt");

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

            // Show every step of the solution?
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
