#ifndef ABSTRACTSUDOKUDATA_H
#define ABSTRACTSUDOKUDATA_H

#include <memory>

class AbstractData
{
    public:

        using handle_type = std::shared_ptr<AbstractData>;

        AbstractData() {};
        virtual ~AbstractData() {};

        // TODO should return const char
        virtual char get_value(const size_t x, const size_t y) const = 0;

    protected:

    private:
};

#endif // ABSTRACTSUDOKUDATA_H
