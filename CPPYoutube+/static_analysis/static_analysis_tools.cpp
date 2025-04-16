#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

struct Entity {};

Entity* loadEntity() {
    if (300 < 500) {
        return new Entity();
    }
    return nullptr;
}

int main(int argc, char const* argv[]) {
    uint32_t width = 800, height = 600;
    uint32_t* buffer = new uint32_t[width * height];

    for (size_t x = 0; x < height; x++) {
        for (size_t y = 0; y < width; y++) {
            buffer[x * height + y] = 0;
        }
    }

    const char* m_string = "Hello";
    char* buffer = new char[strlen(m_string) + 1];
    // strcpy(buffer, m_string);
    return 0;
}