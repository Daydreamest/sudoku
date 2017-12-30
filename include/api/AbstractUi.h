#ifndef ABSTRACTUI_H
#define ABSTRACTUI_H

#include <memory>

#include <LoggerInterface.h>
#include <AbstractData.h>

class AbstractUi : public LoggerInterface
{
    public:

        using handle_type = std::shared_ptr<AbstractUi>;

        virtual ~AbstractUi() {};

        // Get starting data of the sudoku
        virtual AbstractData::handle_type get_initial_values() = 0;

        virtual void print_sudoku(const AbstractData::handle_type s) = 0;

    protected:
        AbstractUi() {};

    private:
};

#endif // ABSTRACTUI_H
