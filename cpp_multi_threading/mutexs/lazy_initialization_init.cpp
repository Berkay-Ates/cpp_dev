#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>

using namespace std;

struct some_resource
{
    // Add resource members here

    void do_something()
    {
    }
};

shared_ptr<some_resource> resource_ptr;
mutex resource_mutex;

void foo()
{
    unique_lock<mutex> lk(resource_mutex);
    if (!resource_ptr)
        resource_ptr.reset(new some_resource());

    lk.unlock();
    resource_ptr->do_something();
}

once_flag resource_flag;

void init_resource2()
{
    resource_ptr.reset(new some_resource());
}

void foo()
{
    call_once(resource_flag, init_resource2);
    resource_ptr->do_something();
}

int main(int argc, char const *argv[])
{

    return 0;
}