#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex m1;
int buffer = 0;

void task(const char* threadNumber, int loopFor) {
    std::unique_lock<std::mutex> lock(m1);
    for (int i = 0; i < loopFor; i++) {
        buffer++;
        std::cout << threadNumber << buffer << std::endl;
    }
}

void task2(const char* threadNumber, int loopFor) {
    std::unique_lock<std::mutex> lock(m1, std::defer_lock);
    lock.lock();
    for (int i = 0; i < loopFor; i++) {
        buffer++;
        std::cout << threadNumber << buffer << std::endl;
    }

    // lock.unlock(); is not required in this scenario because it will unlock automatically whenever
    // the scope end
}

int main(int argc, char const* argv[]) {
    std::thread t2(task2, "T2: ", 10);
    std::thread t1(task2, "T1: ", 10);

    t1.join();
    t2.join();
    return 0;
}