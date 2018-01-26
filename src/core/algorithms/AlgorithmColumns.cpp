#include "AlgorithmColumns.h"

#include <Consts.h>
#include <Logger.h>
#include <ColumnWrapper.h>

extern Logger log;

AlgorithmColumns::AlgorithmColumns(BoardWrapper& brd, SlotSet& res) : AbstractAlgorithm(brd, res)
{
    //ctor
}

AlgorithmColumns::~AlgorithmColumns()
{
    //dtor
}

AlgorithmColumns::handle_type AlgorithmColumns::create(BoardWrapper& brd, SlotSet& res)
{
    return handle_type(new AlgorithmColumns(brd, res));
}

void AlgorithmColumns::operator()()
{
    loop (x, BOARD_MAX_X) {
        auto column = board.get_column(x);

        if (column->is_solved()) {
            continue; // Already solved
        }

        for (auto val : ValueTools::get_value_set()) {
            if (!column->contains(val)) {

                size_t places = column->possible_places_for(val);

                if (places == 0) {
                    log(Log_Level_Error) << "COL Well shit, value " << val << " can't be placed in column " << x << std::endl;
                } else if (places == 1) {
                    Slot found = Slot(column->first_position_for(val), val);
                    results.insert(found);
                    log(Log_Level_Info) << "COL Good insertion found! " << found.toString() << std::endl;
                } else {
//                    log << "COL For value " << val << " there were " << places << " places found in column " << x << std::endl;
                }
            }
        }
    }
}

std::string AlgorithmColumns::get_name()
{
    return "Search for fields in a column that are the only ones to contain a specific value";
}
