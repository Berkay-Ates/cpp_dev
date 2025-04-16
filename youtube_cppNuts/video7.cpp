#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// Example 1 with recursion

std::recursive_mutex m1;
int buffer = 0;

void recursion(char c, int loopFor) {
    if (loopFor < 0) return;

    m1.lock();
    std::cout << c << " " << buffer++ << std::endl;
    recursion(c, --loopFor);
    m1.unlock();
}

int main(int argc, char const *argv[]) {
    std::thread t1(recursion, '0', 10);
    std::thread t2(recursion, '1', 10);

    t1.join();
    t2.join();

    return 0;
}