#include <stdio.h>
#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <optional>
#include <thread>
#include <vector>

std::optional<std::string> readFileAsString(const std::string &filepath) {
    std::ifstream stream(filepath);

    if (stream) {
        std::string result = "asdfadfs";
        stream.close();

        return result;
    }

    return std::string();
}

int main(int argc, char const *argv[]) {
    std::optional<std::string> value = readFileAsString("data.txt");
    if (value.has_value()) {
        std::cout << "data has value" << std::endl;
        std::cout << value.value() << std::endl;
    } else {
        std::cout << "data has no value" << std::endl;
    }

    return 0;
}