#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Constructors
{
public:
    float x, y;

    Constructors()
    {
    }

    Constructors(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    void Init()
    {
        x = 0;
        y = 0;
    }

    void Proint()
    {
        cout << "X: " << x << " Y: " << y << endl;
    }

    ~Constructors()
    {
        printf("Destructors called");
    }
};

class Log
{
public:
    static void write()
    {
    }
};

int main(int argc, char const *argv[])
{

    Constructors constructor(23, 56);
    // constructor.Init();
    constructor.Proint();

    /* Without initialization it will cause to a error */
    cout << constructor.x << " " << constructor.y << endl;

    return 0;
}