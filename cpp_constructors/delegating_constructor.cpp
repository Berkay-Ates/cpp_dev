#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

// Bir constructor icerisinde baska bir constructor cagirmak

// DRY (Don't Repeat Yourself) prensibi icin faydalidir. Ozellikle birden fazla constructor
// overloadi varsa tekrari azaltir.

class Logger {
    std::string name;

   public:
    Logger() : Logger("Default") {}  // Delegation
    Logger(std::string n) : name(n) {}
};

int main(int argc, char const *argv[]) { return 0; }