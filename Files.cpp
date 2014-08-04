#include "Files.h"
#include <iostream> // TODO: Remove
using namespace std;

Files::Files()
{
    ifs.open("asdf.txt");
    if (ifs.fail())
    {
        cout << "File failed to open" << endl;
    }else{
        cout << "Success" << endl;
    }
}

Files::~Files()
{
    ifs.close();
}

void Files::get_string()
{
    ifs.close();
}
