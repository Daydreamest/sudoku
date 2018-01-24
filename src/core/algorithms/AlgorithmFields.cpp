#include "AlgorithmFields.h"

#include <Consts.h>
#include <Logger.h>

extern Logger log;

AlgorithmFields::AlgorithmFields(const FieldBoard& brd, SlotSet& res) : AbstractAlgorithm(brd, res)
{
    //ctor
}

AlgorithmFields::~AlgorithmFields()
{
    //dtor
}

void AlgorithmFields::operator()()
{
    // Search for fields with 1 value possibility
    loop (x, BOARD_MAX_X) {
        loop (y, BOARD_MAX_Y) {
            Value val = board[x][y]->can_be_set();
            if (val != Value_Undefined) {
                log(Log_Level_Info) << "FLD Good inesrtion found! (" << x << ", " << y << ") = " << val << std::endl;
                results.insert(Slot(x, y, val));
            }
        }
    }
}

std::string AlgorithmFields::get_name()
{
    return "Search fo fields with exactly one possible value";
}

AlgorithmFields::handle_type AlgorithmFields::create(const FieldBoard& brd, SlotSet& res)
{
    return std::shared_ptr<AlgorithmFields>(new AlgorithmFields(brd, res));
}
