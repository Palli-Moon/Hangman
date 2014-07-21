#include "Hangman.h"

Hangman::Hangman(): 
stage(0), 
used_letters_arr_size(0), 
wrong_letters_arr_size(0)
{
    // TODO: Change / Remove
    examples[0] = "fish";
    examples[1] = "trumpet";
    examples[2] = "chicago";
    examples[3] = "screwdriver";
    examples[4] = "hangman";
    examples[5] = "who are you?";
    examples[6] = "hello world";

    // TODO: Remove
    str_to_char(examples[5], solution);
    create_guess_string();
}

void Hangman::start_game()
{
    cout << "Welcome to Hangman 0.1b by Palli Moon!" << endl;
    while(true)
    {

    }
}

void Hangman::str_to_char(string inp, char arr[])
{
    int i = 0;
    for (; inp[i] != '\0'; i++)
    {
        arr[i] = inp[i];
    }
    arr[i] = '\0';
}

void Hangman::create_guess_string()
{
    int i = 0;
    for(; solution[i] != '\0'; i++)
    {
        if (solution[i] >= 32 && solution[i] <= 63)
        {
            guess_string[i] = solution[i];
        }else{
            guess_string[i] = '_';
        }
    }
    guess_string[i] = '\0';
}

// TODO: Change params after basic testing
void Hangman::check_letter(char letter)
{
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

bool Hangman::check_solution()
{
    for (int i = 0; guess_string[i] != '\0'; i++)
    {
        if (guess_string[i] >= 65 && guess_string[i] <= 90 ||
            guess_string[i] >= 97 && guess_string[i] <= 122)
        {
            return false;
        }
    }
    return true;
}

char Hangman::get_input()
{
    char c;
    cout << "Guess >> ";
    c = getchar();
    while (!(c >= 65 && c <= 90 ||
             c >= 97 && c <= 122))
    {
        cout << "Please enter a valid guess." << endl;
        cout << "Guess >> ";
        c = getchar();
    }
    return c;
}
   
void Hangman::print_guess_string()
{
    for (int i = 0; guess_string[i] != '\0'; i++)
    {
        cout << guess_string[i] << " ";
    }
}


void Hangman::print_wrong_letters()
{
    cout << "Wrong letters: ";
    for (int i = 0; i < wrong_letters_arr_size; i++)
    {
        cout << wrong_letters[i] << " ";
    }
    cout << endl;
}

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
}
