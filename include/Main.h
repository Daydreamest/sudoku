#ifndef MAIN_H
#define MAIN_H

#include <memory>

#include <Configuration.h>
#include <AbstractUi.h>
#include <Logger.h>
#include <Sudoku.h>

namespace sudoku {

extern ui::Logger log;

class Main
{
    public:

        using handle_type = std::unique_ptr<Main>;
        friend handle_type std::make_unique<Main>();

        static handle_type create();

        virtual ~Main();

        int run();

    protected:
        Main();

    private:
        core::Sudoku::handle_type sudoku;
        AbstractUi::handle_type ui;

        Configuration config;
};

} // namespace sudoku

#endif // MAIN_H
