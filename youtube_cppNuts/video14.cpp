#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

typedef unsigned long int ull;

ull findOdd(ull start, ull end) {
    ull oddSum = 0;
    for (ull i = start; i <= end; i++) {
        if (i & 1) {
            oddSum += i;
        }
    }
    return oddSum;
}

int main(int argc, char const *argv[]) {
    ull start = 0, end = 1900000000;

    std::cout << "Thread created if policy is std::launch::async!!" << std::endl;
    std::future<ull> Oddsum = std::async(std::launch::deferred, findOdd, start, end);

    std::cout << "Waiting for the final result." << std::endl;
    std::cout << "Odd Sum: " << Oddsum.get() << std::endl;

    std::cout << "Completed" << std::endl;

    return 0;
}