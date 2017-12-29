#ifndef MAIN_H
#define MAIN_H

#include <memory>

#include <AbstractLogger.h>
#include <Board.h>
#include <AbstractUi.h>

class Main
{
    public:

        using handle_type = std::unique_ptr<Main>;

        static handle_type create();

        virtual ~Main();

        void run();

        void initialize();

    protected:
        Main();

    private:
        AbstractLogger::handle_type logger;
        SudokuBoard::handle_type board;
        AbstractUi::handle_type ui;
};

#endif // MAIN_H
