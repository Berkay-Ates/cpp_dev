#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <memory>

using namespace std;

class Entity
{

public:
    Entity()
    {
        cout << "Created Entity" << endl;
    }

    ~Entity()
    {
        cout << "Destroyed Entity" << endl;
    }

    void EntityPrint()
    {
        cout << "entity print function is called" << endl;
    }
};

int main(int argc, char const *argv[])
{
    {
        // * Unique PTR
        std::unique_ptr<Entity> entity(new Entity());
        // std::unique_ptr<Entity> entity = make_unique<Entity>();
        //! std::unique_ptr<Entity> entity2 = entity; -> This is false

        entity->EntityPrint();
    }

    {
        //* Shared PTR
        std::shared_ptr<Entity> entityShared = make_shared<Entity>();
        std::shared_ptr<Entity> entityShared2(new Entity());

        std::shared_ptr<Entity> entityTwo = entityShared2;
    }

    return 0;
}