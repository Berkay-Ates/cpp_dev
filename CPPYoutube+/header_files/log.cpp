#include <iostream>
#include "log.h"

using namespace std;

void Log(const char *message)
{
    cout << message << endl;
}

void InitLog(const char *message)
{
    Log(message);
}