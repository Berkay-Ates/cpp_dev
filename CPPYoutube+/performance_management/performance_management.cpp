#include <stdio.h>
#include <stdlib.h>

#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

class Timer {
   public:
    Timer() { m_startTimePoint = std::chrono::high_resolution_clock::now(); }

    ~Timer() { stop(); }

    void stop() {
        auto endTimepoint = std::chrono::high_resolution_clock::now();
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_startTimePoint)
                         .time_since_epoch()
                         .count();

        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint)
                       .time_since_epoch()
                       .count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << "duration" << "us ( " << ms << " )" << std::endl;
    }

   private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimePoint;
};

int main(int argc, char const *argv[]) {
    int value = 0;

    {
        Timer timer;
        for (int i = 0; i < 10000; i++) {
            value += 2;
        }
    }

    std::cout << value << std::endl;

    __debugbreak();
    return 0;
}