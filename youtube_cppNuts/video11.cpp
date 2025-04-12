#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::mutex m1;
std::mutex m2;

void thread1() {
    m1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    m2.lock();
    std::cout << "Critical section of thread Thread One" << std::endl;
    m1.unlock();
    m2.unlock();
}

void thread2() {
    m2.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m1.lock();
    std::cout << "Critical section of thread Thread two" << std::endl;
    m2.unlock();
    m1.unlock();
}

int main(int argc, char const *argv[]) {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();
    return 0;
}