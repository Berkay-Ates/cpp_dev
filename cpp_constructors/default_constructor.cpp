#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

// Default constructor : Hic parametre almaz yada tum parametreleri default deger sahiptir

// Eger hicbir constructor yazilmazsa compiler otomatik olarak default constructoru yazar. Ama
// herhangi bir cosntructor yazilirsa bu defa default constructorun yazilmasi programcinin
// kontrolundedir.

class Device {
   public:
    Device() {}
};

int main(int argc, char const *argv[]) { return 0; }