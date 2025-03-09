#include <stdio.h>
#include <stdlib.h>

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    Timer() { start = std::chrono::high_resolution_clock::now(); }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = start - end;

        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took: " << ms << " ms" << std::endl;
    }
};

void Function() {
    Timer timer;
    for (int i = 0; i < 1000; i++) {
        std::cout << "Hello" << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    // using namespace std::literals::chrono_literals;

    // auto start = std::chrono::high_resolution_clock::now();
    // std::this_thread::sleep_for(1s);

    // auto end = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<float> duration = end - start;

    // std::cout << "Duration: " << duration.count() << std::endl;

    Function();

    return 0;
}