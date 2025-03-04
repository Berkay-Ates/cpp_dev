#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Entity
{
public:
    float x, y;
    void Move(float x, float y)
    {
        this->x = x;
        this->y = y;
    };

    Entity()
    {
    }
};

class Player : public Entity
{
public:
    const char *Name;
    float x, y;

    void Move(float xa, float ya)
    {
        this->x += xa;
        this->y += ya;
    }

    void printName()
    {
        cout << this->x << this->y << endl;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}