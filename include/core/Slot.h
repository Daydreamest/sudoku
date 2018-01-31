#ifndef SLOT_H
#define SLOT_H

#include <set>

#include <Position.h>
#include <Values.h>

namespace sudoku {
namespace core {

// A combination of Position and Value, used in many cases
class Slot
{
    public:
        // Constructor
        Slot(const size_t x, const size_t y, const Value v);

        // Constructor
        Slot(const Position p, const Value v);

        // Destructor
        virtual ~Slot();

        // X coordinate reader
        const size_t get_x() const;

        // Y coordinate reader
        const size_t get_y() const;

        // Value reader
        const Value get_value() const;

        // Position reader
        const Position get_position() const;

        // String version used for logging
        const std::string to_string() const;

    protected:

    private:
        // This slot's Value
        Value val;

        // This slot's position
        Position pos;
};

// Needed fot std::set<Slot>
inline bool operator<(const Slot& lhs, const Slot& rhs)
{
    return lhs.get_position() < rhs.get_position();
}

// Set definition
using SlotSet = std::set<Slot>;

} // namespace core
} // namespace sudoku

#endif // SLOT_H
