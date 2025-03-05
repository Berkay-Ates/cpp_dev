#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

class some_big_object
{
    // Add necessary members and methods
    int data;

public:
    some_big_object() : data(0) {}
    some_big_object(const some_big_object &other) : data(other.data) {}
};
void swap(some_big_object &lhs, some_big_object &rhs);

class X
{
private:
    some_big_object some_detail;
    std::mutex m;

public:
    X(some_big_object const &sd) : some_detail(sd) {}
    friend void swap(X &lhs, X &rhs)
    {
        if (&lhs == &rhs)
            return;
        std::unique_lock<std::mutex> lock_a(lhs.m, std::defer_lock);
        std::unique_lock<std::mutex> lock_b(rhs.m, std::defer_lock);
        std::lock(lock_a, lock_b);
        swap(lhs.some_detail, rhs.some_detail);
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}