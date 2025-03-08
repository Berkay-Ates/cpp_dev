#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

void function()
{
    static int a = 0;
    a++;
    cout << a << endl;
}

class Singleton
{
private:
    static Singleton *sInstance;

public:
    static Singleton &getInstance()
    {
        return *sInstance;
    }
};

// Modern c++ da en cok kullanilan singleton tarzidir.
class StaticSingleton
{
public:
    static StaticSingleton &getInstance()
    {
        static StaticSingleton sInstance;
        return sInstance;
    }
};

Singleton *Singleton::sInstance = nullptr;

int main(int argc, char const *argv[])
{
    function();
    function();
    function();
    function();
    function();
    // a += 90;

    return 0;
}