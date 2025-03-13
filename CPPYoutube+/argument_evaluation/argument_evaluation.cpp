#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

void printArguments(int a, int b) { std::cout << "a: " << a << "b: " << b << std::endl; }

int main(int argc, char const *argv[]) {
    int value = 1;
    printArguments(++value, ++value);
    return 0;
}