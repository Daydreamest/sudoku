#ifndef POSITION_H
#define POSITION_H

#include <cstddef>

class Position
{
    public:
        Position(const size_t xp, const size_t yp);
        virtual ~Position();

        size_t get_x() const;
        size_t get_y() const;

        inline bool operator==(const Position& other);

    protected:

    private:
        size_t x;
        size_t y;

        bool is_correct(const size_t val);
};

#endif // POSITION_H
