#ifndef FILES_H
#define FILES_H
#include <fstream>

class Files
{
public:
    Files();
    ~Files();
    void get_string();
private:
    std::ifstream ifs;
};
#endif
