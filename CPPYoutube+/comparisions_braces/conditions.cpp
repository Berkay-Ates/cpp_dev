#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

int main(int argc, char const *argv[])
{

    for (int i = 0; i < 5; i++)
        cout << "hello world" << endl;

    bool condition = true;
    int i = 0;

    cout << "\nexantric for loop \n " << endl;

    for (; condition;)
    {
        cout << "hello world" << endl;
        i++;
        if (!(i < 5))
            condition = false;
    }

    return 0;
}