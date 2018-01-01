#ifndef VALUES_H
#define VALUES_H

#include <map>
#include <set>

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

using ValueSet = std::set<Value>;

class ValueTools
{
    public:
        virtual ~ValueTools();

        static Value get_value_from_char(const char ch);
        static char get_char_from_value(const Value val);

        static ValueSet get_value_set();

    protected:

    private:
        ValueTools();

        static ValueSet value_set;

        static std::map<char, Value> create_ch_map();
        static std::map<char, Value> ch_to_val_map;

        static std::map<Value, char> create_val_map();
        static std::map<Value, char> val_to_ch_map;
};

#endif // VALUES_H
