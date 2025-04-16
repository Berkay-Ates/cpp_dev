// #include <stdio.h>
// #include <stdlib.h>

// #include <Vector>
// #include <iostream>

// #include "array.h"

// struct Vector3 {
//     float x = 0.0f, y = 0.0f, z = 0.0f;
//     int* m_memoryBlock = nullptr;

//     Vector3() { m_memoryBlock = new int[5]; }

//     Vector3(float scalar) : x(scalar), y(scalar), z(scalar) { m_memoryBlock = new int[5]; }
//     Vector3(float x, float y, float z) : x(x), y(y), z(z) { m_memoryBlock = new int[5]; }

//     Vector3(Vector3&& other) noexcept : x(other.x), y(other.y), z(other.z) {
//         m_memoryBlock = other.m_memoryBlock;
//         other.m_memoryBlock = nullptr;
//         std::cout << "move" << std::endl;
//     }

//     Vector3(const Vector3& other) = delete;

//     ~Vector3() {
//         std::cout << "Destroy" << std::endl;
//         delete[] m_memoryBlock;
//     }

//     Vector3& operator=(const Vector3& other) = delete;

//     Vector3& operator=(Vector3&& other) noexcept {
//         std::cout << "Move" << std::endl;

//         if (this != &other) {
//             // Clean up existing resources
//             delete[] m_memoryBlock;

//             m_memoryBlock = other.m_memoryBlock;
//             other.m_memoryBlock = nullptr;
//             x = other.x;
//             y = other.y;
//             z = other.z;
//         }
//         return *this;
//     }
// };

// template <typename T>
// void printVector(const Vector<T>& vector) {
//     for (size_t i = 0; i < vector.Size(); i++) std::cout << vector[i] << std::endl;

//     std::cout << "-------------------------------------------------" << std::endl;
// }

// template <>
// void printVector(const Vector<Vector3>& vector) {
//     for (size_t i = 0; i < vector.Size(); i++)
//         std::cout << "X: " << vector[i].x << " Y: " << vector[i].y << " Z: " << vector[i].z
//                   << std::endl;

//     std::cout << "-------------------------------------------------" << std::endl;
// }

// int main() {
//     {
//         Vector<std::string> data;
//         data.pushBack("cherno");
//         data.pushBack("c++");
//         data.pushBack("c++");
//         data.pushBack("c++");
//         data.pushBack("c++");
//         data.pushBack("c++");

//         printVector(data);

//         Vector<Vector3> vec3;
//         vec3.pushBack(Vector3(1.0f));
//         vec3.pushBack(Vector3(2, 3, 4));
//         vec3.pushBack(Vector3());

//         printVector(vec3);
//         std::cout << "-------- Emplace Back is running --------" << std::endl;

//         Vector<Vector3> vec3Emp;
//         vec3Emp.emplaceBack(1.0f);
//         vec3Emp.emplaceBack(2, 3, 4);
//         vec3Emp.emplaceBack();
//         printVector(vec3Emp);

//         vec3Emp.popBack();
//         vec3Emp.popBack();
//         printVector(vec3Emp);

//         vec3Emp.emplaceBack();
//         vec3Emp.emplaceBack();
//         printVector(vec3Emp);

//         vec3Emp.clear();

//         vec3Emp.emplaceBack();
//         printVector(vec3Emp);
//     }

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <string>

#include "array.h"  // Assuming this contains the Vector implementation

struct Vector3 {
    float x = 0.0f, y = 0.0f, z = 0.0f;
    int* m_memoryBlock = nullptr;

    Vector3() { m_memoryBlock = new int[5]; }

    Vector3(float scalar) : x(scalar), y(scalar), z(scalar) { m_memoryBlock = new int[5]; }
    Vector3(float x, float y, float z) : x(x), y(y), z(z) { m_memoryBlock = new int[5]; }

    Vector3(Vector3&& other) noexcept : x(other.x), y(other.y), z(other.z) {
        m_memoryBlock = other.m_memoryBlock;
        other.m_memoryBlock = nullptr;
        std::cout << "move" << std::endl;
    }

    Vector3(const Vector3& other) : x(other.x), y(other.y), z(other.z) {
        m_memoryBlock = new int[5];
        for (int i = 0; i < 5; i++) {
            if (other.m_memoryBlock) {
                m_memoryBlock[i] = other.m_memoryBlock[i];
            }
        }
        std::cout << "copy" << std::endl;
    }

    ~Vector3() {
        std::cout << "Destroy" << std::endl;
        delete[] m_memoryBlock;
    }

    Vector3& operator=(const Vector3& other) {
        std::cout << "Copy" << std::endl;
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;

            if (m_memoryBlock == nullptr) {
                m_memoryBlock = new int[5];
            }

            for (int i = 0; i < 5; i++) {
                if (other.m_memoryBlock) {
                    m_memoryBlock[i] = other.m_memoryBlock[i];
                }
            }
        }
        return *this;
    }

    Vector3& operator=(Vector3&& other) noexcept {
        std::cout << "Move" << std::endl;

        if (this != &other) {
            // Clean up existing resources
            delete[] m_memoryBlock;

            m_memoryBlock = other.m_memoryBlock;
            other.m_memoryBlock = nullptr;
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }
};

template <typename T>
void printVector(const Vector<T>& vector) {
    for (size_t i = 0; i < vector.Size(); i++) std::cout << vector[i] << std::endl;

    std::cout << "-------------------------------------------------" << std::endl;
}

template <>
void printVector(const Vector<Vector3>& vector) {
    for (size_t i = 0; i < vector.Size(); i++)
        std::cout << "X: " << vector[i].x << " Y: " << vector[i].y << " Z: " << vector[i].z
                  << std::endl;

    std::cout << "-------------------------------------------------" << std::endl;
}

int main() {
    {
        Vector<std::string> data;
        data.pushBack("cherno");
        data.pushBack("c++");
        data.pushBack("c++");
        data.pushBack("c++");
        data.pushBack("c++");
        data.pushBack("c++");

        printVector(data);

        Vector<Vector3> vec3;
        vec3.pushBack(Vector3(1.0f));
        vec3.pushBack(Vector3(2, 3, 4));
        vec3.pushBack(Vector3());

        printVector(vec3);
        std::cout << "-------- Emplace Back is running --------" << std::endl;

        Vector<Vector3> vec3Emp;
        vec3Emp.emplaceBack(1.0f);
        vec3Emp.emplaceBack(2, 3, 4);
        vec3Emp.emplaceBack();
        printVector(vec3Emp);

        vec3Emp.popBack();
        vec3Emp.popBack();
        printVector(vec3Emp);

        vec3Emp.emplaceBack();
        vec3Emp.emplaceBack();
        printVector(vec3Emp);

        vec3Emp.clear();

        vec3Emp.emplaceBack();
        printVector(vec3Emp);

        std::cout << "*********************************************************" << std::endl;

        Vector<std::string> values;
        values.pushBack("1111");
        values.pushBack("111111");
        values.pushBack("Berkay");
        values.pushBack("ATES");

        std::cout << "Not using iterators" << std::endl;
        for (int i = 0; i < values.Size(); i++) {
            std::cout << values[i] << std::endl;
        }

        std::cout << "Range based for loop" << std::endl;
        for (std::string value : values) {
            std::cout << value << std::endl;
        }

        std::cout << "Iterator" << std::endl;
        for (Vector<std::string>::Iterator it = values.begin(); it != values.end(); it++) {
            std::cout << (*it) << std::endl;
        }
    }

    return 0;
}