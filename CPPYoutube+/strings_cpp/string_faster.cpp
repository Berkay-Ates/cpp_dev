#include <iostream>
#include <thread>
#include <vector>

static uint32_t s_AllocCount = 0;

void* operator new(size_t size) {
    s_AllocCount++;
    std::cout << "Allocating: " << size << " bytes " << std::endl;
    return malloc(size);
}

void operator delete(void* ptr) noexcept {
    s_AllocCount--;
    free(ptr);
}

void printName(const std::string_view name) { std::cout << name << std::endl; }

int main() {
    std::string* name = new std::string("Berkay Ates");

    std::string_view firstName(name->substr(0, 6));  // "Berkay"
    std::string_view lastName(name->substr(7));      // "Ates"

    printName(*name);
    printName(firstName);
    printName(lastName);

    delete name;  // Free memory

    std::cout << s_AllocCount << " allocations" << std::endl;
    return 0;
}
