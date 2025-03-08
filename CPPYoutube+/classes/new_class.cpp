#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Log
{
private:
    int mLoglevel;

public:
    void setLogLevel(int level) { this->mLoglevel = level; }

    void info(const char *message)
    {
        cout << "[INFO]: " << message << endl;
    }

    void error(const char *message)
    {
        cout << "[INFO]: " << message << endl;
    }

    void warn(const char *message)
    {
        cout << "[INFO]: " << message << endl;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}