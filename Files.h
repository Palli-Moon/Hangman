#ifndef FILES_H
#define FILES_H
#include <fstream>
#include <string>
using namespace std;

class Files
{
public:
    Files(char* filename);
    ~Files();
    void clear_eof();
    string get_string(int linenum);
private:
    static const int MAX_ARR_SIZE = 200;

    std::ifstream ifs;
    int file_length; // number of lines in the file
};
#endif
