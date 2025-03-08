#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

enum Example : unsigned char
{
    A = 64,
    B = 65,
    C = 66
};

int main(int argc, char const *argv[])
{

    Example a = Example::A;
    Example b = Example::B;
    Example c = Example::C;

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}