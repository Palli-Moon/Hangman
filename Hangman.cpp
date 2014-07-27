#include "Hangman.h"
#include <stdlib.h>

Hangman::Hangman(): 
stage(0), 
used_letters_arr_size(0), 
wrong_letters_arr_size(0)
{
    int random_num;
    srand(time(NULL));
    random_num = rand() % 7;

    // TODO: Change / Remove
    examples[0] = "fish";
    examples[1] = "trumpet";
    examples[2] = "chicago";
    examples[3] = "screwdriver";
    examples[4] = "hangman";
    examples[5] = "who are you?";
    examples[6] = "hello world";

    // TODO: Remove
    str_to_char(examples[random_num], solution);
    create_guess_string();
}

// Starts game loop
void Hangman::start_game()
{
    for (int i = 0; i < 50; i++) cout << endl;
    cout << "Welcome to Hangman 0.2b by Palli Moon!" << endl;
    cout << endl;
    while(true)
    {
        draw_hangman();
        print_guess_string();
        print_wrong_letters();
        check_letter(get_input());
        for (int i = 0; i < 50; i++) cout << endl;
        if(check_solution()) break;
    }
    // TODO: again?
}

// Casts string to char array
void Hangman::str_to_char(string inp, char arr[])
{
    int i = 0;
    for (; inp[i] != '\0'; i++)
    {
        arr[i] = inp[i];
    }
    arr[i] = '\0';
}

// Returns true IFF the input is a letter of the english alphabet
bool Hangman::check_if_letter(char c)
{
    if ((c >= 65 && c <= 90) ||
        (c >= 97 && c <= 122))
    {
        return true;
    }
    return false;
}

// Creates the guess string to be printed to console
void Hangman::create_guess_string()
{
    int i = 0;
    for(; solution[i] != '\0'; i++)
    {
        if (check_if_letter(solution[i]))
        {
            guess_string[i] = '_';
        }else{
            guess_string[i] = solution[i];
        }
    }
    guess_string[i] = '\0';
}

// Checks if the input is correct
void Hangman::check_letter(char letter)
{
    for (int i = 0; i < used_letters_arr_size; i++)
    {
        if (used_letters[i] == letter)
        {
            cout << "You have already guessed that letter" << endl;
            check_letter(get_input());
            return;
        }
    }
    bool result = false;
    for (int i = 0; guess_string[i] != '\0'; i++)
    {
        if (solution[i] == letter)
        {
            guess_string[i] = solution[i];
            result = true;
        }
    }
    used_letters[used_letters_arr_size] = letter;
    used_letters_arr_size++;

    if (!result)
    {
        wrong_letters[wrong_letters_arr_size] = letter;
        wrong_letters_arr_size++;
        stage++;
    }
}

// Checks if the game has been won / lost
bool Hangman::check_solution()
{
    if (stage >= 6)
    {
        draw_hangman();
        draw_lose_screen();
        cout << "You have lost! The word / phrase was: \"";
        for (int i = 0; solution[i] != '\0'; i++)
        {
            cout << solution[i];
        }
        cout << "\"" << endl;
        return true;
    }

    for (int i = 0; guess_string[i] != '\0'; i++)
    {
        if (guess_string[i] == '_') return false;
    }
    draw_win_screen();
    cout << "You won! Well done!!" << endl;
    return true;
}

// Gets player input and returns the guess if valid
char Hangman::get_input()
{
    // TODO: make better
    char c;
    cout << "Guess >> ";
    cin >> c;
    if (!check_if_letter(c))
    {
        cout << "Please enter a valid guess." << endl;
        cout << "Guess >> ";
        cin >> c;
    }
    cout << endl;
    return c;
}
   
// Prints the guess string in its current form
void Hangman::print_guess_string()
{
    for (int i = 0; guess_string[i] != '\0'; i++)
    {
        cout << guess_string[i] << " ";
    }
    cout << endl;
}

// Prints the letters which were guessed wrong
void Hangman::print_wrong_letters()
{
    cout << "Wrong letters: ";
    for (int i = 0; i < wrong_letters_arr_size; i++)
    {
        cout << wrong_letters[i] << " ";
    }
    cout << endl;
}

// Draws the hangman
void Hangman::draw_hangman()
{
    switch(stage)
    {
        case 0:
            cout << "  _______    "  << endl;
            cout << " |/      |   "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 1: 
            cout << "  _______    "  << endl;
            cout << " |/      |   "  << endl;
            cout << " |      (_)  "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 2:
            cout << "  _______    "  << endl;
            cout << " |/      |   "  << endl;
            cout << " |      (_)  "  << endl;
            cout << " |       |   "  << endl;
            cout << " |       |   "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 3:
            cout << "  _______    "  << endl;
            cout << " |/      |   "  << endl;
            cout << " |      (_)  "  << endl;
            cout << " |      \\|   " << endl;
            cout << " |       |   "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 4:
            cout << "  _______    "  << endl;
            cout << " |/      |   "  << endl;
            cout << " |      (_)  "  << endl;
            cout << " |      \\|/  " << endl;
            cout << " |       |   "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 5:
            cout << "  _______    "  << endl;
            cout << " |/      |   "  << endl;
            cout << " |      (_)  "  << endl;
            cout << " |      \\|/  " << endl;
            cout << " |       |   "  << endl;
            cout << " |      /    " << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 6:
            cout << "  _______    "  << endl;
            cout << " |/      |   "  << endl;
            cout << " |      (_)  "  << endl;
            cout << " |      \\|/  " << endl;
            cout << " |       |   "  << endl;
            cout << " |      / \\  " << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
    }
    cout << endl;
}

// Draws the win screen
void Hangman::draw_win_screen()
{
    cout << "__   __                     _       _ "       << endl;
    cout << "\\ \\ / /__  _   _  __      _(_)_ __ | |"     << endl;
    cout << " \\ V / _ \\| | | | \\ \\ /\\ / / | '_ \\| |" << endl;
    cout << "  | | (_) | |_| |  \\ V  V /| | | | |_|"      << endl;
    cout << "  |_|\\___/ \\__,_|   \\_/\\_/ |_|_| |_(_)"   << endl;
    cout << endl;
}

// Draws the lose screen
void Hangman::draw_lose_screen()
{
    cout << "__   __            _                "     << endl; 
    cout << "\\ \\ / /__  _   _  | | ___  ___  ___ "   << endl;
    cout << " \\ V / _ \\| | | | | |/ _ \\/ __|/ _ \\" << endl;
    cout << "  | | (_) | |_| | | | (_) \\__ \\  __/"   << endl;
    cout << "  |_|\\___/ \\__,_| |_|\\___/|___/\\___|" << endl;
    cout << endl;
}
