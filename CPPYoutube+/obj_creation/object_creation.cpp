#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Job
{
private:
    string m_title;
    double m_salary;

public:
    Job() : m_title("Unknown"), m_salary(0.0) {}
    Job(const string &title, double salary) : m_title(title), m_salary(salary) {}

    const string &getTitle() const { return m_title; }
    double getSalary() const { return m_salary; }
};

class Entity
{
private:
    string m_name;
    Job m_job;

public:
    Entity()
        : m_name("unknown"), m_job() {}

    Entity(const string &name, const Job &job)
        : m_name(name), m_job(job) {}

    const string &getName() const { return m_name; }

    const Job &getJob() const { return m_job; }
};

int main(int argc, char const *argv[])
{

    Entity my_entity;

    {
        Entity *prominent = new Entity();
        Entity temporary;
    }

    cout << my_entity.getName() << endl;

    // the new keyboard calls the entity constructor. While the malloc only reserve memory

    Entity *entity = new Entity();
    Entity *newOne = (Entity *)malloc(sizeof(Entity));

    cout << "entity:" << entity->getName() << endl;

    cout << "malloc Entity: " << newOne->getName() << endl;

    return 0;
}