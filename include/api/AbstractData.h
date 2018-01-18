#ifndef ABSTRACTSUDOKUDATA_H
#define ABSTRACTSUDOKUDATA_H

#include <memory>

#include <Position.h>

class AbstractData
{
    public:

        using handle_type = std::shared_ptr<AbstractData>;

        AbstractData() {};
        virtual ~AbstractData() {};

        // TODO should return const char
        virtual char get_value(const Position pos) const = 0;

    protected:

    private:
};

#endif // ABSTRACTSUDOKUDATA_H
