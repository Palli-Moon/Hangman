#include <iostream>
#include <string> // remove
#include "Hangman.h"
using namespace std;

int main()
{
    Hangman h;
    char arr[30], arr2[30];
    string asdf = "hello how are. you?";
    h.draw_hangman();
    h.str_to_char(asdf, arr);
    for (int i = 0; arr[i] != '\0'; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    h.create_guess_string(arr, arr2);
    h.check_letter('l', arr2);
    for (int i = 0; arr2[i] != '\0'; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
