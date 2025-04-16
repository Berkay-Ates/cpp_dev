#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

struct Orange {
    operator float() { return 5.5f; }
};

void printFloat(float value) { std::cout << value << std::endl; }

template <typename T>
class ScopedPtr {
   public:
    ScopedPtr() = default;
    ScopedPtr(T *ptr) : m_ptr(ptr) {}
    ~ScopedPtr() { delete m_ptr; }

    T *Get() { return m_ptr; }
    const T *Get() const { return m_ptr; }

    bool isValid() const { return m_ptr != nullptr; }

    operator bool() const { return m_ptr != nullptr; }

   private:
    T *m_ptr = nullptr;
};

struct Entity {
    float x = 0.0f, y = 0.0f;
};

void processEntity(const ScopedPtr<Entity> &e) {
    if (e) {
    }
}

int main(int argc, char const *argv[]) {
    // Orange orange;
    // printFloat(orange);
    // std::cout << orange << std::endl;

    ScopedPtr<Entity> e = new Entity();
    Entity *entity = new Entity();

    if (entity) {
        /* code */
    }

    return 0;
}