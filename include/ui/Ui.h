#ifndef UI_H
#define UI_H

#include <memory>

#include <AbstractUi.h>
#include <Initializer.h>
#include <Logger.h>
#include <SudokuData.h>

class Ui : public AbstractUi
{
    public:

        using handle_type = std::shared_ptr<Ui>;

        virtual ~Ui();

        // Get starting data of the sudoku
        virtual AbstractSudokuData::handler_type get_initial_values() override;

        virtual void print_sudoku(const AbstractSudokuData::handler_type s) override;

        static handle_type create();

    protected:
        Ui();

    private:
        Initializer::handle_type init;
        Logger::handle_type logger;
};

#endif // UI_H
