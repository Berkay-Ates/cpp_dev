#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

struct func
{
    int &i;
    func(int &i_) : i(i_) {}
    void operator()()
    {
        for (unsigned j = 0; j < 1000000; j++)
        {
            cout << j << endl;
        }
    }
};

int main(int argc, char const *argv[])
{
    int a = 100000;
    func my_func(a);
    thread my_thread(my_func);

    my_thread.join();

    return 0;
}