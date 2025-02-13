#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

void oneFunction()
{
}

void anotherFunction() {}

int main(int argc, char const *argv[])
{

    thread t1(oneFunction);
    thread t2 = move(t1);

    t1 = thread(anotherFunction);

    thread t3;
    t3 = move(t2);
    // t1 = move(t3);

    t1.join();
    // t2.join();
    t3.join();

    cout << thread::hardware_concurrency() << endl;

    return 0;
}