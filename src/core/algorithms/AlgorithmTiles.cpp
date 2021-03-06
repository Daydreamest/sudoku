#include "AlgorithmTiles.h"

#include <Consts.h>
#include <Logger.h>

namespace sudoku {

extern ui::Logger log;

namespace core {
namespace algorithm {

AlgorithmTiles::AlgorithmTiles(BoardWrapper& brd, SlotSet& res) : AbstractAlgorithm(brd, res)
{
    //ctor
}

AlgorithmTiles::~AlgorithmTiles()
{
    //dtor
}

AlgorithmTiles::handle_type AlgorithmTiles::create(BoardWrapper& brd, SlotSet& res)
{
    return handle_type(new AlgorithmTiles(brd, res));
}

void AlgorithmTiles::operator()()
{
    loop (i, consts::TILE_COUNT) {
        auto tile = board.get_tile(i);

        if (tile->is_solved()) {
            continue; // Already solved
        }

        for (auto val : ValueTools::get_value_set()) {
            if (!tile->contains(val)) {

                size_t places = tile->possible_places_for(val);

                if (places == 0) {
                    log(LogLevel_Error) << "TIL Well shit, value " << val << " can't be placed in tile " << i << std::endl;
                } else if (places == 1) {
                    Slot found = Slot(tile->first_position_for(val), val);
                    results.insert(found);
                    log(LogLevel_Info) << "TIL Good inesrtion found! " << found.to_string() << std::endl;
                } else {
                    log(LogLevel_Debug) << "TIL For value " << val << " there were " << places << " places found in tile " << i << std::endl;
                }
            }
        }
    }
}

std::string AlgorithmTiles::get_name()
{
    return "Search for fields in a tile that are the only ones to contain a specific value";
}

} // namespace algorithm
} // namespace core
} // namespace sudoku
