#ifndef POSITION_H
#define POSITION_H

#include <cstddef>
#include <string>

#include <SudokuException.h>

namespace sudoku {

class Position
{
    public:
        // Constructor with coordinates
        Position(const size_t xp, const size_t yp);

        // Destructor
        virtual ~Position();

        // Coordinates getters
        size_t get_x() const;
        size_t get_y() const;

        // Equality operator
        inline bool operator==(const Position& other);

        // Utility method to print the position in "(x, y)" format
        const std::string to_string() const;

    private:
        // Coordinates
        size_t x;
        size_t y;

        // Check if given coordiantes are correct (within the given range
        bool is_correct(const size_t val);

        // Exception class to throw if coordinates are out of scope
        class PositionException : public SudokuException
        {
            public:
                // Constructor with coordinates
                PositionException(const size_t xp, const size_t yp, const size_t val);

                // Destructor
                virtual ~PositionException();
        };
};

// Comparison operator, needed for contianers
inline bool operator<(const Position& lhs, const Position& rhs)
{
    if (lhs.get_x() == rhs.get_x()) {
        return (lhs.get_y() < rhs.get_y());
    }

    return (lhs.get_x() < rhs.get_x());
}

} // namespace sudoku

#endif // POSITION_H
