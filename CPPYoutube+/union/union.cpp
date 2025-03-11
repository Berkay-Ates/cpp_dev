#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

struct Vector2 {
    float x, y;
};

struct Vector4 {
    union {
        struct {
            float x, y, z, w;
        };
        struct {
            Vector2 a, b;  // a will have x and y, then b will have z and w
        };
    };
};

void printVector2(Vector2& vector2) {
    std::cout << "vector2.x: " << vector2.x << " vector2.y: " << vector2.y << std::endl;
}

int main(int argc, char const* argv[]) {
    struct unionElement {
        union {
            int a;
            double b;
        };
    };

    unionElement ue;
    ue.a = 34;

    std::cout << ue.a << std::endl;
    std::cout << ue.b << std::endl;

    ue.b = 56;

    std::cout << ue.b << std::endl;
    std::cout << ue.a << std::endl;

    Vector4 vector4 = {1.0f, 2.0f, 3.0f, 4.0f};

    printVector2(vector4.a);
    printVector2(vector4.b);
    vector4.x = 2.990f;
    vector4.z = 89898;

    printVector2(vector4.a);
    printVector2(vector4.b);

    return 0;
}