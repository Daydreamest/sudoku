#include "Values.h"

SudokuValueTools::SudokuValueTools()
{
    //ctor
}

SudokuValueTools::~SudokuValueTools()
{
    //dtor
}

SudokuValue SudokuValueTools::get_value_from_char(const char ch)
{
    auto f = ch_to_val_map.find(ch);
    if (f == ch_to_val_map.end())
    {
        return Value_Undefined;
    }

    return f->second;
}


std::map<char, SudokuValue> SudokuValueTools::create_map()
{
    return std::map<char, SudokuValue> {
        {'1', Value_1},
        {'2', Value_2},
        {'3', Value_3},
        {'4', Value_4},
        {'5', Value_5},
        {'6', Value_6},
        {'7', Value_7},
        {'8', Value_8},
        {'9', Value_9}
    };
}

std::map<char, SudokuValue> SudokuValueTools::ch_to_val_map = SudokuValueTools::create_map();
