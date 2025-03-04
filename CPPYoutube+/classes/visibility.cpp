#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Entity
{

private:
    int x, y;

    void Print() { cout << x << " " << y << endl; }

public:
    Entity()
    {
        Print();
        x = 0;
        y = 0;
        Print();
    }
};

int main(int argc, char const *argv[])
{

    Entity e;
    return 0;
}