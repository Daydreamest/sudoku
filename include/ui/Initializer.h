#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <memory>

#include <AbstractSudokuData.h>

class Initializer
{
    public:
        using handle_type = std::shared_ptr<Initializer>;

        static handle_type create();

        virtual ~Initializer();

        AbstractData::handle_type get();

    protected:
        Initializer();

    private:
};

#endif // INITIALIZER_H
