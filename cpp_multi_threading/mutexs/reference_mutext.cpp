#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>

using namespace std;

class SomeData
{
    int a;
    string b;

public:
    void doSomething();
};

class DataWrapper
{
private:
    SomeData data;
    mutex m;

public:
    template <typename Function>
    void processData(Function func)
    {
        lock_guard(mutex) l(m);
        func(data);
    }
};

SomeData *unprotected;
void malicious_function(SomeData &protected_data)
{
    unprotected = &protected_data;
};

DataWrapper x;
void foo()
{
    x.processData(malicious_function);
    unprotected->doSomething();

    // at this stage unprotected is equal to the protected, whatever happens to unprotected also
    // happens to the protected, so the protected is now literally unprotected as well.
}

int main(int argc, char const *argv[])
{

    return 0;
}