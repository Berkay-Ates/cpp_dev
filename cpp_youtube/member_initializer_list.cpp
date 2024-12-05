#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Vector3f
{
public:
    Vector3f() : x(1.0f), y(z), z(2.0f)
    {
        // x = 1.0f;
        // y = 2.0f;
        // z = 3.0f;
    }

    float x, y, z;
};

std::ostream &operator<<(std::ostream &os, const Vector3f &obj)
{
    os << obj.x << "," << obj.y << "," << obj.z;

    return os;
}

int main(int argc, char const *argv[])
{

    Vector3f vector3f;

    cout << vector3f << endl;

    return 0;
}