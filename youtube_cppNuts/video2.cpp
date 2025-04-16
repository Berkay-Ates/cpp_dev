#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

void fun(int x) {
    while (x-- > 10) {
        std::cout << x << std::endl;
    }
    std::cout << std::endl;
}

class Base {
   public:
    void operator()(int x) {
        while (x-- > 0) {
            std::cout << x << std::endl;
        }
    }
};

class Base2 {
   public:
    void run(int x) {
        while (x-- > 10) {
            std::cout << x << std::endl;
        }
    }
};

class Base3 {
   public:
    static void run(int x) {
        while (x-- > 10) {
            std::cout << x << std::endl;
        }
    }
};

int main(int argc, char const *argv[]) {
    auto funLambda = [](int x) {
        while (x-- > 10) {
            std::cout << x << std::endl;
        }
    };

    std::thread t1(fun, 12);
    std::thread t2(funLambda, 16);

    std::thread t3(Base(), 10);

    Base2 b;
    std::thread t4(&Base2::run, &b, 20);

    std::thread t5(&Base3::run, 90);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    return 0;
}