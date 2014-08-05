#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

class Hangman
{
public:
    Hangman();
    void start_game();
private:
    static const int MAX_ARR_SIZE = 200;

    void str_to_char(string inp, char arr[]);
    bool check_if_letter(char c);
    void create_guess_string();
    void check_letter(char letter);
    bool check_solution();
    char get_input();
    void print_guess_string();
    void print_wrong_letters();
    void draw_hangman();
    void draw_win_screen();
    void draw_lose_screen();

    int stage, used_letters_arr_size, wrong_letters_arr_size;
    char used_letters[MAX_ARR_SIZE];
    char wrong_letters[MAX_ARR_SIZE];
    char solution[MAX_ARR_SIZE];
    char guess_string[MAX_ARR_SIZE]; 
  
    string examples[MAX_ARR_SIZE];
};
#endif
