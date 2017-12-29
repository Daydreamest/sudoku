#include <Main.h>

using namespace std;

int main()
{
    Main::handle_type main = Main::create();
    main->initialize();
    main->run();

    return 0;
}
