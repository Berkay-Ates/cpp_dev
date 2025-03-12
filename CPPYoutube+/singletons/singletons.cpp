#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

class Singleton {
   public:
    Singleton(const Singleton&) = delete;  // delete copy constructor for singleton

    static Singleton& Get() {
        static Singleton s_Instance;
        return s_Instance;
    }

    void function() {}

   private:
    Singleton() {}

    static Singleton s_Instance;
};

int main(int argc, char const* argv[]) {
    Singleton& instance = Singleton::Get();

    instance.function();

    return 0;
}