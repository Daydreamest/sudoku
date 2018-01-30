#ifndef MAIN_H
#define MAIN_H

#include <memory>

#include <Configuration.h>
#include <AbstractUi.h>
#include <Logger.h>
#include <Sudoku.h>

namespace sudoku {

// Logger instance
extern ui::Logger log;

class Main
{
    public:
        // Handle type definition
        using handle_type = std::unique_ptr<Main>;
        friend handle_type std::make_unique<Main>();

        // Building method
        static handle_type create();

        // Destructor
        virtual ~Main();

        // Main method to run the program
        int run();

    protected:
        // Constructor
        Main();

    private:
        // Sudoku handle
        core::Sudoku::handle_type sudoku;

        // UI handle
        AbstractUi::handle_type ui;

        // Configuration object
        Configuration config;
};

} // namespace sudoku

#endif // MAIN_H
