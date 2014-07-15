#include "Hangman.h"

Hangman::Hangman()
{
    this->stage = 0;
    this->used_letter_arr_size = 0;
    for (int i = 0; i < MAX_ARR_SIZE; i++)
    {
        this->used_letters[i] = '0';
    }
    
    this->examples[0] = "fish";
    this->examples[1] = "trumpet";
    this->examples[2] = "chicago";
    this->examples[3] = "screwdriver";
    this->examples[4] = "hangman";
    this->examples[5] = "who are you?";
    this->examples[6] = "hello world";
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

void Hangman::create_guess_string(char solution[], char guess_string[])
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

void Hangman::check_letter(char letter, char guess_string[])
{
    for (int i = 0; guess_string[i] != '\0'; i++)
    {
        if (solution[i] == letter)
        {
            guess_string[i] = solution[i];
        }
    }
    used_letters[used_letter_arr_size] = letter;
    used_letter_arr_size++;
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
