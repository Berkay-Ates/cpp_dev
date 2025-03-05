#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

void printHelloWorld()
{
    cout << "Hello World" << endl;
}

int main(int argc, char const *argv[])
{
    thread t(printHelloWorld);
    t.join();

    return 0;
}