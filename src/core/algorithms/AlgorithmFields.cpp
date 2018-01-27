#include "AlgorithmFields.h"

#include <Consts.h>
#include <Logger.h>

namespace sudoku {

extern ui::Logger log;

AlgorithmFields::AlgorithmFields(BoardWrapper& brd, SlotSet& res) : AbstractAlgorithm(brd, res)
{
    //ctor
}

AlgorithmFields::~AlgorithmFields()
{
    //dtor
}

void AlgorithmFields::operator()()
{
    log(Log_Level_Debug) << "FLD Running algorithm: " << get_name() << std::endl;

    loop (x, BOARD_MAX_X) {
        loop (y, BOARD_MAX_Y) {
            Value val = board[x][y]->can_be_set();
            if (val != Value_Undefined) {
                Slot found = Slot(x, y, val);
                log(Log_Level_Info) << "FLD Good inesrtion found! " << found.toString() << std::endl;
                results.insert(found);
            }
        }
    }
}

std::string AlgorithmFields::get_name()
{
    return "Search for fields with exactly one possible value";
}

AlgorithmFields::handle_type AlgorithmFields::create(BoardWrapper& brd, SlotSet& res)
{
    return handle_type(new AlgorithmFields(brd, res));
}

} // namespace sudoku
