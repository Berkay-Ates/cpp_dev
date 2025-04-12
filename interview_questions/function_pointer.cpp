#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>
//? What is function pointer and how to call it
//* Normal pointer variables stores the addres of another variables, function pointer store address
//* of another funciton

int add(int x, int y) { return x + y; }

int (*fun)(int, int) = add;

//? Calling a function using a function pointer

int fun1(int (*fun)(int, int), int x, int y) {
    int c = fun(x, y);
    return c;
}

int result = fun1(fun, 90, 78);

//? How to pass a function pointer as an argument

//? How to return a function pointer

//? How to use arrays of function pointers

//* function pointers will be in a array, which contains only function pointers.

//? Where to use function pointers
//* for the callbacks, qsort like funcitons,

int main(int argc, char const *argv[]) { return 0; }