#ifndef POSITION_H
#define POSITION_H

#include <cstddef>
#include <string>

class Position
{
    public:
        Position(const size_t xp, const size_t yp);
        virtual ~Position();

        size_t get_x() const;
        size_t get_y() const;

        inline bool operator==(const Position& other);

        const std::string toString() const;

    protected:

    private:
        size_t x;
        size_t y;

        bool is_correct(const size_t val);
};

inline bool operator<(const Position& lhs, const Position& rhs)
{
    if (lhs.get_x() == rhs.get_x()) {
        return (lhs.get_y() < rhs.get_y());
    }

    return (lhs.get_x() < rhs.get_x());
}


#endif // POSITION_H
