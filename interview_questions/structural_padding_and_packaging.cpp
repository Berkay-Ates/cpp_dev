// question:what is structural padding and packing in C/c++
// answer:it is a way to speed up cpu optimization

#include <iostream>
#include <thread>
#include <vector>

#pragma pack(1)  // this disables the paddings

struct Base {
    char a;
    char b;
    int i;
    char c;
};

int main(int argc, char const *argv[]) {
    std::cout << sizeof(Base) << std::endl;
    return 0;
}