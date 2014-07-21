#include <iostream>
#include <string> // remove
#include "Hangman.h"
using namespace std;

int main()
{
    Hangman h;
    h.draw_hangman();
    h.print_guess_string();
    cout << endl;
    h.check_letter('y');
    h.check_letter('o');
    h.check_letter('x');
    h.draw_hangman();
    h.print_guess_string();
    cout << endl;
    h.print_wrong_letters();
    return 0;
}
