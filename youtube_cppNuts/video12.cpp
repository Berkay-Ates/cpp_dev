#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

long long bankBalance = 0;
std::mutex m1, m2;

void addMoney(long long val) {
    m1.lock();
    bankBalance += val;
    m1.unlock();
}

int main(int argc, char const *argv[]) {
    std::thread t1(addMoney, 1000);
    std::thread t2(addMoney, 1000);

    t1.join();
    t2.join();

    std::cout << "Bank balance: " << bankBalance << std::endl;
    return 0;
}