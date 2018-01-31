#ifndef VALUES_H
#define VALUES_H

#include <map>
#include <set>

namespace sudoku {
namespace core {

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

// Set container definition
using ValueSet = std::set<Value>;

class ValueTools
{
    public:
        // Destructor
        virtual ~ValueTools();

        // Translate char to value
        static Value get_value_from_char(const char ch);

        // Translate value to char
        static char get_char_from_value(const Value val);

        // Get a container of all possible values
        static ValueSet get_value_set();

    private:
        // Constructor
        ValueTools();

        // Container of all possible values
        static ValueSet value_set;

        // A map of char to value
        static std::map<char, Value> ch_to_val_map;

        // Create a map of char to value
        static std::map<char, Value> create_ch_map();

        // A map of value to char
        static std::map<Value, char> val_to_ch_map;

        // Create a map of value to char
        static std::map<Value, char> create_val_map();
};

} // namespace core
} // namespace sudoku

#endif // VALUES_H
