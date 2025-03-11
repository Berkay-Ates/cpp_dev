#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

struct Entity {
    int x, y;
};

int main(int argc, char const *argv[]) {
    int a = 45;
    double value = *(double *)&a;
    value = 0.0;
    // this is type punning, take the address of int, then cast it to double
    // pointer, then access that value, and assign it to the vlaue
    std::cout << "valued (double): " << value << std::endl;
    std::cout << "a (int): " << value << std::endl;

    Entity e = {5, 8};
    int *position = (int *)&e;

    std::cout << position[0] << std::endl;
    std::cout << position[1] << std::endl;

    int y = *(int *)((char *)&e + 4);
    std::cout << "reached y value by egzantrik way: " << y << std::endl;

    return 0;
}