#ifndef ABSTRACTSUDOKUDATA_H
#define ABSTRACTSUDOKUDATA_H

#include <memory>

#include <Position.h>

namespace sudoku {

class AbstractData
{
    public:
        // Handle type definition
        using handle_type = std::shared_ptr<AbstractData>;

        AbstractData() {};
        virtual ~AbstractData() {};

        // Get a printable (char) value in the given position
        virtual const char get_value(const Position pos) const = 0;
};

} // namespace sudoku

#endif // ABSTRACTSUDOKUDATA_H
