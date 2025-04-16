#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <variant>
#include <vector>

int main() {
    // variantlar her turlu veri tipini kendi icerisinde farkli bir veri tipi olarak saklar
    std::variant<std::string, int, double> cherno = "cherno";

    std::cout << cherno.index() << std::endl;
    cherno = 90;
    std::cout << cherno.index() << std::endl;
    cherno = "asdfalj";

    std::cout << cherno.index() << std::endl;
    cherno = 90.9009;

    if (auto value = std::get_if<std::string>(&cherno)) {
        std::cout << "cherno is string" << std::endl;
    }

    cherno = "Cherno";
    if (auto value = std::get_if<std::string>(&cherno)) {
        std::cout << "cherno is string" << std::endl;
    }

    return 0;
}