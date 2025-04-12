#include <stdio.h>
#include <stdlib.h>

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

std::mutex mu;
std::condition_variable cond;
std::deque<int> buffer;
const unsigned int maxBufferSize = 50;

void producer(int val) {
    while (val) {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []() { return buffer.size() < maxBufferSize; });
        buffer.push_back(val);
        std::cout << "Produced: " << val << std::endl;
        val--;
        locker.unlock();
        cond.notify_one();
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> locker(mu);
        cond.wait(locker, []() { return buffer.size() > 0; });
        int val = buffer.back();
        buffer.pop_back();
        std::cout << "Consumed: " << val << std::endl;
        locker.unlock();
        cond.notify_one();
    }
}

int main(int argc, char const *argv[]) {
    std::thread t1(producer, 100);
    std::thread t2(consumer);

    t1.join();
    t2.join();
    return 0;
}