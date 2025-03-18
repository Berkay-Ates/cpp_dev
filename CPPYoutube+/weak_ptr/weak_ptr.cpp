#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <memory>
#include <thread>
#include <vector>

struct Object {};

struct Manager {
    std::shared_ptr<Object> obj;
};

int main() {
    Object* obj = new Object;

    delete obj;

    std::shared_ptr<Object> obj = std::make_shared<Object>();

    Manager manager;
    manager.obj = obj;
    return 0;
}