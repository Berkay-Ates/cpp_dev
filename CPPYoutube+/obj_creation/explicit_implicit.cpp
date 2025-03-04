#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Entity
{
private:
    string m_name;
    int age;

public:
    Entity(const string &name) : m_name(name), age(-1) { cout << "name initializer called. " << endl; }
    explicit Entity(const string &name) : m_name(name), age(-1) { cout << "name initializer called. " << endl; }

    Entity(const int age) : m_name("unknown"), age(age) { cout << "age initializer called. " << endl; }
    explicit Entity(const int age) : m_name("unknown"), age(age) { cout << "age initializer called. " << endl; }
};

int main(int argc, char const *argv[])
{

    Entity Age(5);
    Entity Name("Age initializer");

    // implicit conversion
    Entity impAge = 56;
    Entity impNAme = string("Helloworld");

    return 0;
}