#include "Menu.h"

void Menu::welcome_screen()
{
    cout << "========================================" << endl;
    cout << "    Welcome to Hangman by Palli Moon    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "To play, enter the letter you would like" << endl;
    cout << "guess and press ENTER. It is possible to" << endl;
    cout << "guess more than 1 letter at a time, but " << endl;
    cout << "it is not recommended." << endl;
    cout << "ended." << endl;
    cout << endl;
    cout << "Press ENTER to continue" << endl;
    cin.get();
}
