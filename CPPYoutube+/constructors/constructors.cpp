#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Vector2
{
public:
    float x, y;

    void printValues(string name)
    {
        cout << name << "X: " << this->x << " Y: " << this->y << endl;
    }
};

int main()
{
    Vector2 a = {7, 8};
    Vector2 b = a;

    // above items are completely different from each others

    a.printValues("A : ");

    b.printValues("B : ");

    a.x = 32;
    a.printValues("A : ");
    b.printValues("B : ");

    b.y = 90;
    a.printValues("A : ");
    b.printValues("B : ");

    return 0;
}