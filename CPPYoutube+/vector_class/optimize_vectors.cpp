#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

struct Vertex
{
    float x, y, z;

    Vertex(float x, float y, float z) : x(x), y(y), z(z)
    {
    }

    Vertex(const Vertex &vertex) : x(vertex.x), y(vertex.y), z(vertex.z)
    {
        cout << " Copied" << endl;
    }
};

int main()
{
    vector<Vertex> vertices;
    vertices.reserve(40);
    vertices.push_back({1, 2, 3});
    vertices.push_back({1, 2, 3});
    vertices.emplace_back(Vertex(1, 2, 3));
    vertices.emplace_back(Vertex(1, 2, 3));
    vertices.emplace_back(Vertex(1, 2, 3));

    return 0;
}