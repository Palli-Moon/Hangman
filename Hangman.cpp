#include <stdlib.h>
#include "Hangman.h"
#include "Files.h"

Hangman::Hangman(): 
stage(0), 
used_letters_arr_size(0), 
wrong_letters_arr_size(0)
{
  srand(time(NULL));

  solution = fetch_string_from_file("mistery.txt"); // TODO: Change filename
  create_guess_string();
}

// Starts game loop
void Hangman::start_game() {
  for (int i = 0; i < 50; ++i) cout << endl;
  cout << "Welcome to Hangman by Palli Moon!" << endl;
  cout << endl;
  while (true) {
    draw_hangman();
    print_guess_string();
    print_wrong_letters();
    check_letter(get_input());
    for (int i = 0; i < 50; ++i) cout << endl;
    if(check_solution()) break;
  }
  // TODO: Check if player wants to go again?
}

// Gets a random line from a file
string Hangman::fetch_string_from_file(string filename) {
  str_to_char(filename, this->filename);

  Files f(this->filename);
  return f.get_string(rand());
}

// Casts string to char array
void Hangman::str_to_char(string inp, char arr[]) {
  int i = 0;
  for (; inp[i] != '\0'; ++i)
  {
    arr[i] = inp[i];
  }
  arr[i] = '\0';
}

// Returns true IFF the input is a letter of the english alphabet
// TODO: fix caps bug
bool Hangman::check_if_letter(char c) {
  if ((c >= 65 && c <= 90) ||
      (c >= 97 && c <= 122))
  {
    return true;
  }
  return false;
}

// Creates the guess string to be printed to console
void Hangman::create_guess_string() {
  int i = 0;
  for (; solution[i] != '\0'; ++i) {
    if (check_if_letter(solution[i])) {
      guess_string[i] = '_';
    } else {
      guess_string[i] = solution[i];
    }
  }
  guess_string[i] = '\0';
}

// Checks if the input is correct
void Hangman::check_letter(char letter) {
  for (int i = 0; i < used_letters_arr_size; ++i) {
    if (used_letters[i] == letter) {
      cout << "You have already guessed that letter" << endl;
      check_letter(get_input());
      return;
    }
  }
  bool result = false;
  for (int i = 0; guess_string[i] != '\0'; ++i) {
    if (solution[i] == letter) {
      guess_string[i] = solution[i];
      result = true;
    }
  }
  used_letters[used_letters_arr_size] = letter;
  used_letters_arr_size++;

  if (!result) {
    wrong_letters[wrong_letters_arr_size] = letter;
    wrong_letters_arr_size++;
    stage++;
  }
}

// Checks if the game has been won / lost
bool Hangman::check_solution() {
  if (stage >= 10) {
    draw_hangman();
    draw_lose_screen();
    cout << "You have lost! The word / phrase was: \"";
    for (int i = 0; solution[i] != '\0'; ++i) {
      cout << solution[i];
    }
    cout << "\"" << endl;
    return true;
  }

  for (int i = 0; guess_string[i] != '\0'; ++i) {
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
    for (int i = 0; guess_string[i] != '\0'; ++i)
    {
        cout << guess_string[i] << " ";
    }
    cout << endl;
}

// Prints the letters which were guessed wrong
void Hangman::print_wrong_letters()
{
    cout << "Wrong letters: ";
    for (int i = 0; i < wrong_letters_arr_size; ++i)
    {
        cout << wrong_letters[i] << " ";
    }
    cout << endl;
}

// Draws the hangman
void Hangman::draw_hangman()
{
    // Hangman ascii art gotten from:
    // http://ascii.co.uk/art/hangman

    // TODO: More difficulty levels?
    switch(stage)
    {
        case 0:
            cout << "             "  << endl;
            cout << "             "  << endl;
            cout << "             "  << endl;
            cout << "             "  << endl;
            cout << "             "  << endl;
            cout << "             "  << endl;
            cout << "             "  << endl;
            cout << "  ___        "  << endl;
            break;
        case 1:
            cout << "             "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 2:
            cout << "  _______    "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 3:
            cout << "  _______    "  << endl;
            cout << " | /         "  << endl;
            cout << " |/          "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 4:
            cout << "  _______    "  << endl;
            cout << " | /     |   "  << endl;
            cout << " |/          "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 5: 
            cout << "  _______    "  << endl;
            cout << " | /     |   "  << endl;
            cout << " |/     (_)  "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 6:
            cout << "  _______    "  << endl;
            cout << " | /     |   "  << endl;
            cout << " |/     (_)  "  << endl;
            cout << " |       |   "  << endl;
            cout << " |       |   "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 7:
            cout << "  _______    "  << endl;
            cout << " | /     |   "  << endl;
            cout << " |/     (_)  "  << endl;
            cout << " |      \\|   " << endl;
            cout << " |       |   "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 8:
            cout << "  _______    "  << endl;
            cout << " | /     |   "  << endl;
            cout << " |/     (_)  "  << endl;
            cout << " |      \\|/  " << endl;
            cout << " |       |   "  << endl;
            cout << " |           "  << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 9:
            cout << "  _______    "  << endl;
            cout << " | /     |   "  << endl;
            cout << " |/     (_)  "  << endl;
            cout << " |      \\|/  " << endl;
            cout << " |       |   "  << endl;
            cout << " |      /    " << endl;
            cout << " |           "  << endl;
            cout << " |___        "  << endl;
            break;
        case 10:
            cout << "  _______    "  << endl;
            cout << " | /     |   "  << endl;
            cout << " |/     (_)  "  << endl;
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
    // Win screen ascii word art generated at:
    // http://patorjk.com/software/taag

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
    // Lose screen ascii word art generated at:
    // http://patorjk.com/software/taag

    cout << "__   __            _                "     << endl; 
    cout << "\\ \\ / /__  _   _  | | ___  ___  ___ "   << endl;
    cout << " \\ V / _ \\| | | | | |/ _ \\/ __|/ _ \\" << endl;
    cout << "  | | (_) | |_| | | | (_) \\__ \\  __/"   << endl;
    cout << "  |_|\\___/ \\__,_| |_|\\___/|___/\\___|" << endl;
    cout << endl;
}
