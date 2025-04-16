#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

// Bir nesneyi baska bir nesneden ayni turde kopyalamak icin kullanilir
// Varayilan olarak compiler shallow copy yapan bir copy constructor uretir. Ancak sinifin dinamik
// bellegi yonetmesi durumunda deep_copy implement etmek zorunludur.

class CopyConstructor {
    int *data;

   public:
    CopyConstructor(const CopyConstructor &other) {
        // deep copy gerekebilir.
        data = new int;
        *data = *(other.data);
    }
};

int main(int argc, char const *argv[]) { return 0; }