#include <stdio.h>
#include <stdlib.h>

#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

std::condition_variable cv;
std::mutex m;
long balance = 0;

void addMoney(int money) {
    std::lock_guard<std::mutex> lg(m);
    balance += money;
    std::cout << "Amount Added Current Balance: " << balance << std::endl;
    cv.notify_one();
}

void withdrawMoney(int money) {
    std::unique_lock<std::mutex> ul(m);
    cv.wait(ul, []() { return balance != 0 ? true : false; });
    if (balance >= money) {
        balance -= money;
        std::cout << "Amount Deduced: " << money << std::endl;
    } else {
        std::cout << "Amount can't be deduced, current Balance is less than " << money << std::endl;
    }
    std::cout << "Current balance is: " << balance << std::endl;
}

int main(int argc, char const *argv[]) {
    std::thread t1(withdrawMoney, 500);
    std::thread t2(addMoney, 500);

    t1.join();
    t2.join();

    return 0;
}