#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

// Compiler'a constructor un varsayilan sekilde kullanilmasini veya kullanilmamasini soylemek icin

// Bu ozellikle non-copyable siniflarda onemlidir. Ornegin std::unique_ptr benzeri benzeri bir nesne
// tek sahipli olacaksa copy constructor silinmelidir.

class Driver {
   public:
    Driver() = default;               // default constructor isteyerek tanimlanir
    Driver(const Driver &) = delete;  // kopyalanmasi engellenir.
};

int main(int argc, char const *argv[]) { return 0; }