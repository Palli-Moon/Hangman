#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <string>
using namespace std;

class Hangman
{
public:
    Hangman();
    // TODO: Make methods private

    // Turns a string input into a character array
    void str_to_char(string inp, char arr[]);

    // Prepares the guess string using the solution string
    void create_guess_string();

    // Checks if letter is part of solution and adjusts the guess string
    void check_letter(char letter);

    // Returns false unless all letters have been guessed
    bool check_solution();

    // Draws the guess string
    void print_guess_string();

    // Draws the gangman
    void draw_hangman();
private:
    static const int MAX_ARR_SIZE = 200;

    int stage, used_letter_arr_size;
    char used_letters[MAX_ARR_SIZE];
    char solution[MAX_ARR_SIZE];
    char guess_string[MAX_ARR_SIZE]; 

    string examples[MAX_ARR_SIZE];
};
#endif
