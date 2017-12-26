#ifndef ABSTRACTSUDOKUDATA_H
#define ABSTRACTSUDOKUDATA_H

#include <array>
#include <memory>

class AbstractSudokuData
{
    public:
        AbstractSudokuData();
        virtual ~AbstractSudokuData();

        virtual std::array<char, 9> operator[] (int x) = 0;

    protected:

    private:
};

using AbstractSudokuData_Pointer = std::shared_ptr<AbstractSudokuData>;

#endif // ABSTRACTSUDOKUDATA_H
