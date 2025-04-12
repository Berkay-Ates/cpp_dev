#include <stdio.h>
#include <stdlib.h>

int main() {
    // int* ip = (int*)malloc(sizeof(int));

    int* ip = NULL;
    *ip = 100;

    printf("%d", *ip);
}