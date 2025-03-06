#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

struct Vertex
{
    float x, y, z;
    double elements[100000];
};

ostream &operator<<(ostream &stream, const Vertex &vertex)
{
    stream << vertex.x << vertex.y << vertex.z << endl;
    return stream;
}

void functionForEfficiency(const vector<Vertex> &vector)
{
}

int main()
{
    Vertex *vertices = new Vertex[5];
    vertices[4] = Vertex();
    vertices[4].x = 34;
    vertices[4].y = 56;
    vertices[4].z = 60;

    cout << vertices[4] << endl;

    vector<Vertex> vectorVertex;
    vectorVertex.push_back({1, 4, 5});
    vectorVertex.push_back({6, 7, 8});
    vectorVertex.push_back({11, 14, 9});

    // send the elements by their references
    functionForEfficiency(vectorVertex);

    for (int i = 0; i < 10000; i++)
        vectorVertex.push_back({9, 0, 8});

    for (int i = 0; (int)i < vectorVertex.size() - 10000; i++)
    {
        cout << vectorVertex[i] << endl;
    }

    cout << " <<<<<<<<<<<<< " << endl;

    for (Vertex v : vectorVertex)
        cout << v << endl;

    // erase item at the index of 0
    vectorVertex.erase(vectorVertex.begin() + 1);

    // delete all the list
    vectorVertex.clear();

    return 0;
}