#include <iostream> // TODO: Remove
#include "Files.h"
using namespace std;

Files::Files(char *filename)
{
    ifs.open(filename);
    int currline = 0;
    if (ifs.fail()) {
        cout << "File failed to open" << endl;
    }else{
        for (string line; getline(ifs, line); ++currline);
        file_length = currline;
        clear_eof();
    }
}

Files::~Files()
{
    ifs.close();
}

void Files::clear_eof()
{
    ifs.clear();
    ifs.seekg(0, ios::beg);
}

string Files::get_string(int linenum)
{
    clear_eof();
    int currline = 0;
    linenum %= file_length;
    for (string line; getline(ifs, line); ++currline)
        if (currline == linenum)
            return line;
    return "error";
}
