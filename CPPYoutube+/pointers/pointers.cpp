#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <mem.h>

using namespace std;

int main(int argc, char const *argv[])
{

    int var = 8;

    void *hello = nullptr;

    hello = &var;

    cout << hello << endl;
    cout << (*(int *)hello) << endl;
    cout << var << endl;

    cout << "----------" << endl;
    *(int *)hello = 23;

    cout << hello << endl;
    cout << (*(int *)hello) << endl;
    cout << var << endl;

    char *myChar = new char[8];
    memset(myChar, 'A', 8);
    // char *ptr = myChar; // Use a separate pointer to traverse

    cout << "MyChar:" << myChar << endl;
    for (int i = 0; i < 8; i++)
    {
        cout << (void *)myChar << endl; // Print pointer address
        cout << *myChar << endl;        // Print pointer address
        myChar++;
    }

    cout << "Final MyChar position: " << (void *)myChar << endl;
    delete[] myChar; // Always free dynamically allocated memory

    return 0;
}