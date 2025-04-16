#include <stdio.h>
#include <stdlib.h>

#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

int x = 0, y = 0;
std::mutex m1, m2;

void doSomeWorkForSeconds(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void incrementXY(int& XorY, std::mutex& m, const char* desc) {
    for (int i = 0; i < 5; i++) {
        m.lock();
        ++XorY;
        std::cout << desc << XorY << '\n';
        m.unlock();
        doSomeWorkForSeconds(1);
    }
}

void consumeXY() {
    int useCount = 5;
    int XplusY = 0;
    while (1) {
        int lockResult = std::try_lock(m1, m2);
        if (lockResult == -1) {
            if (x != 0 && y != 0) {
                --useCount;
                XplusY += x + y;
                x = 0;
                y = 0;
                std::cout << "XplusY: " << XplusY << std::endl;
            }
            m1.unlock();
            m2.unlock();
            if (useCount == 0) break;
        }
    }
}

int main(int argc, char const* argv[]) {
    std::thread t1(incrementXY, std::ref(x), std::ref(m1), " X : ");
    std::thread t2(incrementXY, std::ref(y), std::ref(m2), " Y : ");
    std::thread t3(consumeXY);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}