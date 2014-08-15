#include "Menu.h"
#include "Hangman.h"

void Menu::welcome_screen()
{
    Hangman::clear_screen();
    cout << "            ========================================" << endl;
    cout << "                Welcome to Hangman by Palli Moon    " << endl;
    cout << "            ========================================" << endl;
    cout << endl;
    cout << "            To play, enter the letter you would like" << endl;
    cout << "            guess and press ENTER. It is possible to" << endl;
    cout << "            guess more than 1 letter at a time. How-" << endl;
    cout << "            ever, doing so is not recommended." << endl;
    cout << endl;
    cout << "            Press ENTER to continue" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cin.get();
}
