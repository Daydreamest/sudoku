#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <memory>
#include <string>

#include <AbstractData.h>

namespace sudoku {
namespace ui {

class Initializer
{
    public:
        // Handle type definition
        using handle_type = std::shared_ptr<Initializer>;

        // Building method
        static handle_type create(const std::string input_file_name);

        // Destructor
        virtual ~Initializer();

        // Reader of the starting data
        AbstractData::handle_type get();

    protected:
        // Constructor
        Initializer(const std::string input_file_name);

    private:
        // Input filr name
        const std::string ifile;
};

} //namespace ui
} // namespace sudoku

#endif // INITIALIZER_H
