#ifndef VALUES_H
#define VALUES_H

#include <map>

// Possible values of a single Sudoku field
enum SudokuValue {
    Value_Undefined = 0,
    Value_1,
    Value_2,
    Value_3,
    Value_4,
    Value_5,
    Value_6,
    Value_7,
    Value_8,
    Value_9
};

class SudokuValueTools
{
    public:
        virtual ~SudokuValueTools();

        static SudokuValue get_value_from_char(const char ch);

    protected:

    private:
        SudokuValueTools();

        static std::map<char, SudokuValue> create_map();

        static std::map<char, SudokuValue> ch_to_val_map;
};

#endif // VALUES_H
