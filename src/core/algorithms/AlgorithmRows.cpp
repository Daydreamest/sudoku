#include "AlgorithmRows.h"

#include <Consts.h>
#include <Logger.h>

namespace sudoku {

extern ui::Logger log;

namespace core {
namespace algorithm {

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
    loop (y, consts::BOARD_MAX_Y) {
        auto row = board.get_row(y);

        if (row->is_solved()) {
            continue; // Already solved
        }

        for (auto val : ValueTools::get_value_set()) {
            if (!row->contains(val)) {

                size_t places = row->possible_places_for(val);

                if (places == 0) {
                    log(LogLevel_Error) << "ROW Well shit, value " << val << " can't be placed in row " << y << std::endl;
                } else if (places == 1) {
                    Slot found = Slot(row->first_position_for(val), val);
                    results.insert(found);
                    log(LogLevel_Info) << "ROW Good inesrtion found! " << found.to_string() << std::endl;
                } else {
                    log(LogLevel_Debug) << "ROW For value " << val << " there were " << places << " places found in row " << y << std::endl;
                }
            }
        }
    }
}

std::string AlgorithmRows::get_name()
{
    return "Search for fields in a row that are the only ones to contain a specific value";
}

} // namespace algorithm
} // namespace core
} // namespace sudoku
