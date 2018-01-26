#include "AlgorithmRows.h"

#include <Consts.h>
#include <Logger.h>
#include <RowWrapper.h>

extern Logger log;

AlgorithmRows::AlgorithmRows(BoardWrapper& brd, SlotSet& res) : AbstractAlgorithm(brd, res)
{
    //ctor
}

AlgorithmRows::~AlgorithmRows()
{
    //dtor
}

AlgorithmRows::handle_type AlgorithmRows::create(BoardWrapper& brd, SlotSet& res)
{
    return handle_type(new AlgorithmRows(brd, res));
}

void AlgorithmRows::operator()()
{
    loop (y, BOARD_MAX_Y) {
        auto row = board.get_row(y);

        if (row->is_solved()) {
            continue; // Already solved
        }

        for (auto val : ValueTools::get_value_set()) {
            if (!row->contains(val)) {

                size_t places = row->possible_places_for(val);

                if (places == 0) {
                    log(Log_Level_Error) << "ROW Well shit, value " << val << " can't be placed in row " << y << std::endl;
                } else if (places == 1) {
                    Slot found = Slot(row->first_position_for(val), val);
                    results.insert(found);
                    log(Log_Level_Info) << "ROW Good inesrtion found! (" << found.get_x() << ", " << y << ") = " << val << std::endl;
                } else {
//                    log << "ROW For value " << val << " there were " << places_for_val << " places found in row " << y << std::endl;
                }
            }
        }
    }
}

std::string AlgorithmRows::get_name()
{
    return "Search for fields in a row that are the only ones to contain a specific value";
}
