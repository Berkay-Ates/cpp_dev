#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

// Singleton pattern veya yalnizca friend siniflarca erisim icin kullanilir

class Bootloader {};

class System {
   private:
    System() {}
    friend class Bootloader;
};

// Bu tur bir yapi Singleton, Factory Method veya Controlled Instantiation icin kullanilir.
// Genellikle cekirdek icinde init() fonksiyonlariyla birlikte gorulur.

int main(int argc, char const *argv[]) { return 0; }