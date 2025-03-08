#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Entity
{

public:
    void printEntity() const
    {
        cout << "Hello!" << endl;
    }
};

class ScopedPtr
{
private:
    Entity *m_obj;

public:
    ScopedPtr(Entity *entity) : m_obj(entity)
    {
    }

    Entity *operator->()
    {
        return m_obj;
    }

    const Entity *operator->() const
    {
        return m_obj;
    }

    ~ScopedPtr()
    {
        delete m_obj;
    }
};

struct Vector3
{
    float x, y, z;
};

int main(int argc, char const *argv[])
{

    // Entity e;
    // e.printEntity();

    // Entity *eptr = &e;

    // eptr->printEntity();

    // Entity &entityRef = *eptr;
    // entityRef.printEntity();

    ScopedPtr entity = new Entity();
    entity->printEntity();

    const ScopedPtr entityConst = new Entity();
    entityConst->printEntity();

    // offset
    int offsetX = (int)&((Vector3 *)0)->x;
    int offsetY = (int)&((Vector3 *)0)->y;
    int offsetZ = (int)&((Vector3 *)0)->z;

    cout << "Offset X: " << offsetX << endl;
    cout << "Offset Y: " << offsetY << endl;
    cout << "Offset Z: " << offsetZ << endl;

    return 0;
}