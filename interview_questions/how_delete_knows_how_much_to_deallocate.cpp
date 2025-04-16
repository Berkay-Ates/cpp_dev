#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

int const n = 10;

class Base {
   public:
    int b_var;
};

int main(int argc, char const* argv[]) {
    Base* bp = new Base;

    delete[] bp;

    return 0;
}