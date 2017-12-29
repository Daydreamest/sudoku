#ifndef ABSTRACTSUDOKUDATA_H
#define ABSTRACTSUDOKUDATA_H

#include <array>
#include <memory>

class AbstractSudokuData
{
    public:

        using handler_type = std::shared_ptr<AbstractSudokuData>;

        AbstractSudokuData() {};
        virtual ~AbstractSudokuData() {};

        virtual std::array<char, 9> operator[] (int x) = 0;

        // TODO should return const char
        virtual char get_value(const size_t x, const size_t y) const = 0;

    protected:

    private:
};

#endif // ABSTRACTSUDOKUDATA_H
