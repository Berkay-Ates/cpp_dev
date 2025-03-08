#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <functional>

using namespace std;

void printerFunction(int a, string name)
{
    for (int i = 0; i < a; i++)
        cout << name << endl;
}

int main(int argc, char const *argv[])
{
    int a = 3;
    string name = "berkay";

    auto binded = bind(printerFunction, ref(a), ref(name));

    binded();
    name[0] = '1';
    a = 5;
    binded();
    return 0;
}