#include <Main.h>

int main()
{
    sudoku::Main::handle_type main = sudoku::Main::create();

    main->run();

    return 0;
}
