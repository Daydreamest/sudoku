#ifndef MAIN_H
#define MAIN_H

#include <memory>

#include <AbstractUi.h>
#include <Logger.h>
#include <Sudoku.h>

namespace sudoku {

extern Logger log;

class Main
{
    public:

        using handle_type = std::unique_ptr<Main>;
        friend handle_type std::make_unique<Main>();

        static handle_type create();

        virtual ~Main();

        void run();

    protected:
        Main();

    private:
        Sudoku::handle_type sudoku;
        AbstractUi::handle_type ui;
};

} // namespace sudoku

#endif // MAIN_H
