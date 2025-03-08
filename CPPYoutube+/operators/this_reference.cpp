#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Entity
{
    float x;
    float y;

    Entity(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    float getX() const
    {
        const Entity *e = this;
        return this->x;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}