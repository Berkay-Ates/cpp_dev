#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <unordered_map>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (size_t i = 0; i < values.size(); i++) {
        std::cout << values[i] << std::endl;
    }

    for (int i : values) {
        std::cout << i << ", ";
    }

    std::cout << std::endl;

    for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++) {
        std::cout << *it << std::endl;
    }

    using ScoreMap = std::unordered_map<std::string, int>;
    using ScoreMapConstIter = ScoreMap::const_iterator;
    ScoreMap map;
    map["cherno"] = 5;
    map["c++"] = 12;

    for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++) {
        std::cout << "First: " << (*it).first << " Second: " << (*it).second << std::endl;
    }

    std::cout << "using auto: " << std::endl;
    for (auto kv : map) {
        std::cout << "First: " << kv.first << " Second: " << kv.second << std::endl;
    }
    return 0;
}