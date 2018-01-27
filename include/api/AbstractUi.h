#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

#include <memory>

#include <AbstractData.h>

namespace sudoku {

class AbstractUi
{
    public:

        using handle_type = std::shared_ptr<AbstractUi>;

        virtual ~AbstractUi() {};

        // Get starting data of the sudoku
        virtual AbstractData::handle_type get_initial_values() = 0;

        // Show sudoku on the screen
        virtual void print_sudoku(const AbstractData::handle_type s) = 0;

    protected:
        AbstractUi() {};

    private:
};

} // namespace sudoku

#endif // ABSTRACTUI_H
