#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <memory>

#include <AbstractData.h>

namespace sudoku {
namespace ui {

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

} //namespace ui
} // namespace sudoku

#endif // INITIALIZER_H
