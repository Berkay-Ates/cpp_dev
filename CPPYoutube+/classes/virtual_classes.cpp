#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Entity
{
public:
    std::string GetName() { return "Entity"; }
};

class Player : public Entity
{
private:
    string m_name;

public:
    Player(const string &name) : m_name(name) {}
    string GetName() { return m_name; }
};

int main(int argc, char const *argv[])
{

    Entity *e = new Entity();
    cout << e->GetName() << endl;

    Player *p = new Player("Berkay");
    cout << p->GetName() << endl;

    return 0;
}