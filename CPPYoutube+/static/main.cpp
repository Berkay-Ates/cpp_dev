#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

extern int n_Static;

int main(int argc, char const *argv[])
{
    cout << n_Static << endl;

    return 0;
}