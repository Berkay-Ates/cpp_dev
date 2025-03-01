#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

void changeValue(int &a)
{
    a++;
}

void changeValue2(int *a)
{
    a++;
}

int main(int argc, char const *argv[])
{
    int a = 5;
    int &ref = a;
    ref = 34;

    cout << "ref:" << &ref << endl;
    cout << "ref value: " << ref << endl;

    cout << "a:" << &a << endl;
    cout << "a value:" << a << endl;

    a = 11;

    cout << " a is: " << a << endl;

    cout << "ref:" << &ref << endl;
    cout << "ref value: " << ref << endl;

    cout << "a:" << &a << endl;
    cout << "a value:" << a << endl;

    ref = 34;

    cout << " ref is: " << ref << endl;

    cout << "ref:" << &ref << endl;
    cout << "ref value: " << ref << endl;

    cout << "a:" << &a << endl;
    cout << "a value:" << a << endl;

    cout << "changeValue(a):" << a << endl;
    changeValue(a);
    cout << "changeValue(a):" << a << endl;

    cout << "changeValue2(a):" << a << endl;
    changeValue2(&a);
    cout << "changeValue2(a):" << a << endl;

    return 0;
}