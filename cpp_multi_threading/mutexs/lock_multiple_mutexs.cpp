#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

class SomeBigObject
{
};
void swap(SomeBigObject &lhs, SomeBigObject &rhs);

class X
{
private:
    SomeBigObject some_detail;
    std::mutex m;

public:
    X(SomeBigObject const &sd) : some_detail(sd) {}
    friend void swap(X &lhs, X &rhs)
    {
        if (&lhs == &rhs)
            return;
        std::lock(lhs.m, rhs.m);
        std::lock_guard<std::mutex> lock_a(lhs.m, std::adopt_lock);
        std::lock_guard<std::mutex> lock_b(rhs.m, std::adopt_lock);
        swap(lhs.some_detail, rhs.some_detail);
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}