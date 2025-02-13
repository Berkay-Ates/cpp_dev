#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class background_task
{
    void do_something() const
    {
        cout << "something " << endl;
    }

    void do_something_else() const
    {
        cout << "something else" << endl;
    }

public:
    void operator()() const
    {
        do_something();
        do_something_else();
    }
};

int main(int argc, char const *argv[])
{

    background_task f;
    thread my_thread(f);

    my_thread.join();

    cout << "end of the thread" << endl;
    f();
    return 0;
}