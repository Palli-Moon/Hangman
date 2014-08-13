#ifndef FILES_H
#define FILES_H
#include <fstream>
#include <string>
using namespace std;

#define MAX_ARR_SIZE 200

class Files
{
public:
    Files(char *filename);
    ~Files();
    string get_string(int linenum);
private:
    void clear_eof();

    ifstream ifs;
    int file_length; // number of lines in the file
};
#endif
