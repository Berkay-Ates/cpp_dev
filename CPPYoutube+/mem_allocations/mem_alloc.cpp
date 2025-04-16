#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <memory>
#include <thread>
#include <vector>

struct AllocationMetrics {
    uint32_t TotalAllocated = 0;
    uint32_t TotalFreed = 0;

    uint32_t currentUsage() { return TotalAllocated - TotalFreed; }
};

static AllocationMetrics sAllocationMetrics;

void *operator new(size_t size) {
    sAllocationMetrics.TotalAllocated += size;
    std::cout << "Allocating " << size << " bytes" << std::endl;
    return malloc(size);
}

void operator delete(void *memory, size_t size) {
    sAllocationMetrics.TotalFreed -= size;
    std::cout << "Freeing " << size << " bytes" << std::endl;
    free(memory);
}

struct Object {
    int x, y, z;
};

static void printUsage() {
    std::cout << "Memory usage: " << sAllocationMetrics.currentUsage() << std::endl;
}

int main(int argc, char const *argv[]) {
    Object *obj = new Object;
    printUsage();

    {
        std::unique_ptr<Object> obj = std::make_unique<Object>();
        printUsage();
    }

    printUsage();
    std::string string = "Cherno";
    printUsage();
    return 0;
}