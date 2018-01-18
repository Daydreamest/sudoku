#ifndef SLOT_H
#define SLOT_H

#include <set>

#include <Position.h>
#include <Values.h>

class Slot
{
    public:
        Slot(const size_t x, const size_t y, const Value v);
        Slot(const Position p, const Value v);
        virtual ~Slot();

        const size_t get_x() const;
        const size_t get_y() const;
        const Value get_value() const;
        const Position get_position() const;

    protected:

    private:
        Value val;
        Position pos;
};

// Needed fot std::set<Slot>
inline bool operator<(const Slot& lhs, const Slot& rhs)
{
    return lhs.get_position() < rhs.get_position();
}

using SlotSet = std::set<Slot>;

#endif // SLOT_H
