#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

int main() {
    std::vector<int> values = {1, 0, 3, 8, 4, 5, 6, 2, 9};
    std::sort(values.begin(), values.end(), std::greater<int>());  // reverse sort
    std::sort(values.begin(), values.end());                       // normal sort
    std::sort(values.begin(), values.end(),
              [](int a, int b) { return a > b; });  // lambda function, reverse

    std::sort(values.begin(), values.end(),
              [](int a, int b) { return a < b; });  // lambda function, normal sort

    for (int value : values) {
        std::cout << value;
    }
    return 0;
}