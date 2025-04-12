#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> vec;

    std::cout << "size: " << vec.size() << std::endl;
    std::cout << "capacity: " << vec.size() << std::endl;

    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);

    std::cout << "size: " << vec.size() << std::endl;
    std::cout << "capacity: " << vec.size() << std::endl;
    return 0;
}