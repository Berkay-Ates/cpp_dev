#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

int main(int argc, char const *argv[]) {
    int i = 10;

    int &r = i;
    int *p = &i;

    return 0;
}