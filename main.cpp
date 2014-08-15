#include "Hangman.h"
#include "Menu.h"
using namespace std;

int main()
{
    Menu m;
    m.welcome_screen();

    Hangman h;
    h.start_game();
    return 0;
}
