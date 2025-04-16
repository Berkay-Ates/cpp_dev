#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

void fun() {
    static int s = 0;
    int count = 100000;
    while (count--) {
        ++s;
    }
    std::cout << s << std::endl;
}

int main(int argc, char const *argv[]) {
    std::thread t1(fun);
    std::thread t2(fun);

    t1.join();
    t2.join();

    return 0;
}