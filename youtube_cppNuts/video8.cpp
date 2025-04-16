#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex m1;
int buffer = 0;

void task(const char *threadNumber, int loopFor) {
    std::lock_guard<std::mutex> lock(m1);
    for (int i = 0; i < loopFor; i++) {
        buffer++;
        std::cout << threadNumber << buffer << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    std::thread t1(task, "T0", 10);
    std::thread t2(task, "T1", 10);

    t1.join();
    t2.join();

    return 0;
}