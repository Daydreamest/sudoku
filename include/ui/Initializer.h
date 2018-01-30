#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <memory>

#include <AbstractData.h>

namespace sudoku {
namespace ui {

class Initializer
{
    public:
        // Handle type definition
        using handle_type = std::shared_ptr<Initializer>;

        // Building method
        static handle_type create();

        // Destructor
        virtual ~Initializer();

        // Reader of the starting data
        AbstractData::handle_type get();

    protected:
        // Constructor
        Initializer();

    private:
};

} //namespace ui
} // namespace sudoku

#endif // INITIALIZER_H
