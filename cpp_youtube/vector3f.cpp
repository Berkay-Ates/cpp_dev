#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Vector3f
{
public:
    Vector3f()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    float x, y, z;

    Vector3f operator+(const Vector3f &rhs) const
    {
        Vector3f result;
        result.x = x + rhs.x;
        result.y = y + rhs.y;
        result.z = z + rhs.z;

        return result;
    }

    Vector3f operator++()
    {
        x = x + 1.f;
        y = y + 1.f;
        z = z + 1.f;
        return *this;
    }

    bool operator==(const Vector3f &rhs) const
    {
        if (x == rhs.x && y == rhs.y && z == rhs.z)
            return true;

        return false;
    }
};
std::ostream &operator<<(std::ostream &os, const Vector3f &obj)
{
    os << obj.x << "," << obj.y << "," << obj.z;

    return os;
}

// bool operator==(const Vector3f &lhs, const Vector3f &rhs)
// {
//     if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z)
//         return true;

//     return false;
// }

int main(int argc, char const *argv[])
{
    Vector3f vector3f;
    vector3f.x = 3.f;
    vector3f.y = 2.f;
    vector3f.z = 1.f;

    Vector3f vector3f2;
    vector3f2.x = 1.f;
    vector3f2.y = 2.f;
    vector3f2.z = 3.f;

    Vector3f vec3f3;
    vec3f3 = vector3f2 + vector3f;

    cout << vec3f3.x << " " << vec3f3.y << " " << vec3f3.z << endl;

    ++vec3f3;

    cout << vec3f3.x << " " << vec3f3.y << " " << vec3f3.z << endl;

    cout << vec3f3 << endl;

    cout << (vec3f3 == vector3f2) << endl;
    cout << (vector3f2 == vector3f2) << endl;

    return 0;
}