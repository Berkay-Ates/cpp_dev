#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int counter = 0;
std::mutex mtx;

// to have right result there must be lock instead of try_lock

void increaseTheCounterFor100000Time() {
    for (int i = 0; i < 100000; i++) {
        if (mtx.try_lock()) {
            ++counter;
            // mtx.unlock();
        }
    }
}

int main(int argc, char const *argv[]) {
    std::thread t1(increaseTheCounterFor100000Time);
    std::thread t2(increaseTheCounterFor100000Time);

    t1.join();
    t2.join();

    std::cout << "Counter could increase up to: " << counter << std::endl;

    return 0;
}