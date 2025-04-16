#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

// Tek argumanli constructorlarda istemsiz donusumleri engellemek icin kurgulanir

class ExplicitConstructor {
   public:
    explicit ExplicitConstructor(int port) {}
};

// bu ozellikle Kernel-level API'lerde veya donanim soytlamada onemli; yanlislikla int bir degerle
// nesne olusturulmasini engeller

int main(int argc, char const *argv[]) {
    // ExplicitConstructor explicit = 5;
    ExplicitConstructor explicit_value(5);
    return 0;
}