#ifndef UI_H
#define UI_H

#include <memory>
#include <string>

#include <AbstractUi.h>
#include <Initializer.h>
#include <AbstractData.h>

namespace sudoku {
namespace ui {

class Ui : public AbstractUi
{
    public:
        // Handle type definition
        using handle_type = std::shared_ptr<Ui>;

        // Destructor
        virtual ~Ui();

        // Get starting data of the sudoku
        virtual AbstractData::handle_type get_initial_values() override;

        // Show sudoku on the screen
        virtual void print_sudoku(const AbstractData::handle_type s) override;

        // Building method
        static handle_type create(const std::string input_file_name);

    protected:
        // Constructor
        Ui(const std::string input_file_name);

    private:
        // Initializer handle
        Initializer::handle_type init;
};

} //namespace ui
} // namespace sudoku

#endif // UI_H
