#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

static bool is_finished = false;

void DoWork() {
    using namespace std::literals::chrono_literals;

    std::cout << "Child thread id: " << std::this_thread::get_id() << std::endl;

    while (!is_finished) {
        std::cout << "working" << std::endl;
        std::this_thread::sleep_for(1s);
    }
}

int main() {
    std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;
    std::thread worker(DoWork);

    std::cin.get();
    is_finished = true;

    worker.join();

    std::cin.get();
}