#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

#define WAIT std::cin.get()
#define LOG(x) std::cout << x << std::endl

#ifdef PR_DEBUG
#define LOGGER(x) std::cout << x << std::endl
#elif defined(PR_RELEASE)
#else
#define LOGGER(x)
#endif

using namespace std;

int main(int argc, char const *argv[]) {
    WAIT;

    LOG("Hello world");

    WAIT;
    return 0;
}