#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

// R-Value referans (&&) ile cagrilir. Kaynagin kaynagin kaynak verilerini kopyalamadan tasir.

// Performans kritik sistemlerde move semantics ile temporary objeleri kopyalamak yerine tasimak cok
// onemlidir. Heapden allocation yapilan siniflardak kesinlikle onerilir.

class Buffer {
    int* data;

   public:
    Buffer(Buffer&& other) noexcept {
        data = other.data;
        other.data = nullptr;
    }
};

int main(int argc, char const* argv[]) { return 0; }