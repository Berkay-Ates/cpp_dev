#include <iostream>
#include <semaphore>
#include <thread>

std::binary_semaphore smphSignalMainThread{0}, smphSignalThreadToMain{0};

void threadProc() {
    smphSignalMainThread.acquire();

    std::cout << "Thread get the role" << std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(3));

    smphSignalMainThread.release();
}

int main() { return 0; }
