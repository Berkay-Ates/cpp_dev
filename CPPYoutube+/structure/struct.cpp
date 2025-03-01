#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

struct Vec2
{
    float x, y;
    void add(const Vec2 &other)
    {
        x += other.x;
        y += other.y;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}