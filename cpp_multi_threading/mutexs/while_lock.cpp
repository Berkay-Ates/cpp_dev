#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <mutex>
using namespace std;

bool flag;
mutex m;

void wait_for_flag()
{
    unique_lock<mutex> lk(m);
    while (!flag)
    {
        lk.unlock();
        this_thread::sleep_for(chrono::milliseconds(100));
        lk.lock();
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}