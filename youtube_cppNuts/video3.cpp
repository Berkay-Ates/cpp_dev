#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int moneyAmount = 0;

std::mutex m;

void addMoney() {
    std::lock_guard<std::mutex> lock(m);
    for (int i = 0; i < 1000000; i++) {
        moneyAmount += 1;
    }
}
void subtractMoney() {
    m.lock();
    for (int i = 0; i < 1000000; i++) {
        moneyAmount -= 1;
    }
    m.unlock();
}

int main(int argc, char const *argv[]) {
    std::thread t1(addMoney);
    std::thread t2(subtractMoney);

    std::cout << moneyAmount << std::endl;

    t1.join();
    std::cout << moneyAmount << std::endl;

    t2.join();

    std::cout << moneyAmount << std::endl;
    return 0;
}