#include <Main.h>

int main()
{
    // Create Main class
    sudoku::Main::handle_type main = sudoku::Main::create();

    // Run the programme
    return main->run();
}
