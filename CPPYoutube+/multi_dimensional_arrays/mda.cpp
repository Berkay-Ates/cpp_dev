#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int *array = new int[50];
    int **arrayPTR = new int *[50];

    for (int i = 0; i < 50; i++) {
        arrayPTR[i] = new int[50];
    }

    int ***a3d = new int **[50];
    for (int i = 0; i < 50; i++) {
        a3d[i] = new int *[50];
        for (int j = 0; j < 50; j++) {
            int **ptr = a3d[i];
            ptr[j] = new int[50];
        }
    }

    for (int i = 0; i < 50; i++) {
        delete[] arrayPTR[i];
    }
    delete[] arrayPTR;
}