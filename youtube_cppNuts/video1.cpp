#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

typedef unsigned long long ull;

class SumCalculator {
   private:
    std::mutex mtx;
    ull oddSum = 0;
    ull evenSum = 0;

   public:
    void findEven(ull start, ull end) {
        ull localEvenSum = 0;
        for (ull i = start; i < end; i++) {
            if ((i & 1) == 0) {
                localEvenSum += i;
            }
        }

        std::lock_guard<std::mutex> lock(mtx);
        evenSum += localEvenSum;
    }

    void findOdd(ull start, ull end) {
        ull localOddSum = 0;
        for (ull i = start; i < end; i++) {
            if ((i & 1) == 1) {
                localOddSum += i;
            }
        }

        std::lock_guard<std::mutex> lock(mtx);
        oddSum += localOddSum;
    }

    void calculateParallel(ull start, ull end) {
        ull range = end - start;
        ull mid = start + range / 2;

        // Create threads to split the work
        std::thread t1(&SumCalculator::findEven, this, start, mid);
        std::thread t2(&SumCalculator::findEven, this, mid, end);
        std::thread t3(&SumCalculator::findOdd, this, start, mid);
        std::thread t4(&SumCalculator::findOdd, this, mid, end);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
    }

    void printResults(std::chrono::microseconds duration) {
        std::cout << "OddSum: " << oddSum << std::endl;
        std::cout << "EvenSum: " << evenSum << std::endl;
        std::cout << "Seconds: " << duration.count() / 1000000.0 << std::endl;
    }

    ull getOddSum() const { return oddSum; }
    ull getEvenSum() const { return evenSum; }
};

int main() {
    ull start = 0;
    ull end = 1900000000;

    SumCalculator calculator;

    auto startTime = std::chrono::high_resolution_clock::now();

    calculator.calculateParallel(start, end);

    auto stopTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime);

    calculator.printResults(duration);

    return 0;
}