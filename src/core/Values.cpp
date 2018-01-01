#include "Values.h"

ValueTools::ValueTools()
{
    //ctor
}

ValueTools::~ValueTools()
{
    //dtor
}

Value ValueTools::get_value_from_char(const char ch)
{
    auto f = ch_to_val_map.find(ch);
    if (f == ch_to_val_map.end())
    {
        return Value_Undefined;
    }

    return f->second;
}

char ValueTools::get_char_from_value(const Value val)
{
    auto f = val_to_ch_map.find(val);
    if (f == val_to_ch_map.end())
    {
        return ' ';
    }

    return f->second;
}

ValueSet ValueTools::get_value_set()
{
        return value_set;
}

std::map<char, Value> ValueTools::create_ch_map()
{
    return std::map<char, Value> {
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

std::map<Value, char> ValueTools::create_val_map()
{
    return std::map<Value, char> {
        {Value_1, '1'},
        {Value_2, '2'},
        {Value_3, '3'},
        {Value_4, '4'},
        {Value_5, '5'},
        {Value_6, '6'},
        {Value_7, '7'},
        {Value_8, '8'},
        {Value_9, '9'}
    };
}

std::map<char, Value> ValueTools::ch_to_val_map = ValueTools::create_ch_map();

std::map<Value, char> ValueTools::val_to_ch_map = ValueTools::create_val_map();

ValueSet ValueTools::value_set = ValueSet {
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
