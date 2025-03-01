#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 5;
    bool comparisionResult = x == 5;

    if (comparisionResult == true)
    {
        cout << "true" << endl;
    }

    cout << comparisionResult << endl;

    return 0;
}