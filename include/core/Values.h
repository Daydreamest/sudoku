#ifndef VALUES_H
#define VALUES_H

#include <map>

// Possible values of a single Sudoku field
enum Value {
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

class ValueTools
{
    public:
        virtual ~ValueTools();

        static Value get_value_from_char(const char ch);
        static char get_char_from_value(const Value val);

    protected:

    private:
        ValueTools();

        static std::map<char, Value> create_ch_map();
        static std::map<char, Value> ch_to_val_map;

        static std::map<Value, char> create_val_map();
        static std::map<Value, char> val_to_ch_map;
};

#endif // VALUES_H
