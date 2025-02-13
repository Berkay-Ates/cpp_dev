#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

void do_something()
{
    cout << "something " << endl;
}

void do_something_else()
{
    cout << "something else" << endl;
}

int main(int argc, char const *argv[])
{

    thread mythread([]
                    {
                     do_something();
                     do_something_else(); });
    mythread.join();
    return 0;
}