#include "Sudoku.h"

#include <ColumnWrapper.h>                  // TODO remove?
#include <Consts.h>                  // TODO remove?
#include <CoreData.h>
#include <Logger.h>
#include <RowWrapper.h>                  // TODO remove?
#include <TileWrapper.h>                  // TODO remove?

extern Logger log;

Sudoku::Sudoku()// : board(create_empty_array())
{
    //ctor

    // Set algorithms
    algorithms.initialize(board, found_fields);
}

Sudoku::~Sudoku()
{
    //dtor
}

Sudoku::handle_type Sudoku::create()
{
    return handle_type(new Sudoku);
}

void Sudoku::set_data(const AbstractData::handle_type d)
{
    loop (x, BOARD_MAX_X) {
        loop (y, BOARD_MAX_Y) {
            char ch_val = d->get_value(Position(x, y));
            Value s_val = ValueTools::get_value_from_char(ch_val);

            set_value(Slot(x, y, s_val));
        }
    }
}

const AbstractData::handle_type Sudoku::get_data() const
{
    CoreData::handle_type result = CoreData::create();

    loop (x, BOARD_MAX_X) {
        loop (y, BOARD_MAX_Y) {
            if (board[x][y]->get_value() != Value_Undefined) {
                result->set_value(Slot(x, y, board[x][y]->get_value()));
            }
        }
    }

    return result;
}

void Sudoku::set_value(const Slot slot)
{
    // For undefined values do nothing
    if (slot.get_value() == Value_Undefined) {
        return;
    }

    board.set_value(slot);
}

bool Sudoku::is_solved() const
{
    loop (x, BOARD_MAX_X) {
        auto column = board.get_column(x);
        if (!column->is_solved()) {
            return false;
        }
    }

    return true;
}

bool Sudoku::solve_step()
{
    algorithms.run();

    if (found_fields.empty()) {
        return false;
    }

    for (auto found : found_fields) {
        set_value(found);
        log(Log_Level_Info) << "SLV found solution for field " << found.toString() << std::endl;
    }
    found_fields.clear();

    return true;
//    TEST();
}

void Sudoku::TEST()
{
}
