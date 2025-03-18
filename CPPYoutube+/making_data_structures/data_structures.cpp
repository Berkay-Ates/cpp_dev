#include <stdio.h>
#include <stdlib.h>

#include <array>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

template <typename T, size_t S>
class Array {
   public:
    Array() {}

    constexpr size_t Size() const { return S; }

    T& operator[](size_t index) {
        if (index > S) __debugbreak();
        return m_data[index];
    }
    const T& operator[](size_t index) const { return m_data[index]; }

    T* Data() { return m_data; }
    const T* Data() const { return m_data; }

   private:
    T m_data[S];
};

int main(int argc, char const* argv[]) {
    int size = 5;
    Array<int, 5> arr;

    static_assert(arr.Size() < 10, "Size must be less than 10");

    Array<std::string, arr.Size()> strArr;

    std::cout << "Size: " << arr.Size() << std::endl;
    for (size_t i = 0; i < arr.Size(); i++) {
        std::cout << arr[i] << std::endl;
    }
    // memset(&arr[0], 0, arr.Size() * sizeof(int));
    return 0;
}