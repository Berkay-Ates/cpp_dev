#include <stdio.h>
#include <stdlib.h>

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

int value = 0;

void increase_the_value() { value = value + 1; }

int main(int argc, char const *argv[]) {
    // std::thread t1(increase_the_value);
    // std::thread t2(increase_the_value);
    // std::thread t3(increase_the_value);
    // std::thread t4(increase_the_value);

    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();

    int min_val = INT_MAX;
    for (int i = 0; i < 1000; ++i) {
        value = 0;
        std::thread t1(increase_the_value);
        std::thread t2(increase_the_value);
        std::thread t3(increase_the_value);
        std::thread t4(increase_the_value);
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        if (value < min_val) min_val = value;
    }
    std::cout << "Minimum observed: " << min_val << "\n";

    std::cout << "Value of i:" << value << std::endl;

    return 0;
}