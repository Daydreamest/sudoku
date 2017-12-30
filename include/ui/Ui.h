#ifndef UI_H
#define UI_H

#include <memory>

#include <AbstractUi.h>
#include <Initializer.h>
#include <AbstractSudokuData.h>

class Ui : public AbstractUi
{
    public:

        using handle_type = std::shared_ptr<Ui>;

        virtual ~Ui();

        // Get starting data of the sudoku
        virtual AbstractData::handle_type get_initial_values() override;

        virtual void print_sudoku(const AbstractData::handle_type s) override;

        static handle_type create();

    protected:
        Ui();

    private:
        Initializer::handle_type init;
};

#endif // UI_H
