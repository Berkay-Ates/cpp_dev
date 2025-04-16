#include <stdio.h>
#include <stdlib.h>

#include <chrono>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

void findOdd(std::promise<unsigned long long> &&OddSumPromise, unsigned long long start,
             unsigned long long end) {
    unsigned long long oddSum = 0;
    for (unsigned long long i = start; i <= end; i++) {
        if (i & 1) {
            oddSum += i;
        }
    }
    OddSumPromise.set_value(oddSum);
}

int main(int argc, char const *argv[]) {
    unsigned long long start = 0;
    unsigned long long end = 1900000000;

    std::promise<unsigned long long> OddSum;
    std::future<unsigned long long> OddFuture = OddSum.get_future();

    std::cout << "Thread Created." << std::endl;

    std::thread t1(findOdd, std::move(OddSum), start, end);

    std::cout << "Waiting for the result." << std::endl;

    std::cout << "OddSum: " << OddFuture.get() << std::endl;

    std::cout << "Completed." << std::endl;
    t1.join();

    return 0;
}