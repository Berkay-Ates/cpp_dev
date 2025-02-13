#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

void parameterFunction(int a, string &value)
{
    int i = 0;
    for (i = 0; i < a; i++)
    {
        cout << value << endl;
    }
    value[0] = 'a';
}
int main()
{
    string name = "berkay";
    int a = 3;
    thread t(parameterFunction, a, &name);

    t.join();
    cout << name << endl;

    cout << "Reference of a:" << &a << endl;
    cout << "Reference of name:" << &name << endl;

    return 0;
}