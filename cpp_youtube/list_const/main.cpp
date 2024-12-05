#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "member_init_list.hpp"

using namespace std;

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