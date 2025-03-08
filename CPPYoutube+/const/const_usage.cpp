#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class ConstUsage
{
public:
    int aVal = 34;
    const int *aPtr = &aVal;
};

int main(int argc, char const *argv[])
{

    const int MAX_AGE = 90;
    int age = 34;
    int *a = new int;

    *a = 2;

    a = (int *)&MAX_AGE;

    cout << *a << endl;

    const int *b = (int *)&MAX_AGE; // The content is constant
    int *const c = (int *)&MAX_AGE; // the pointer pointed address is fixed

    // *b = 45;
    // c = &age;

    return 0;
}