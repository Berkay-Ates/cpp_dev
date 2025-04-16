#include <stdio.h>
#include <stdlib.h>

#include <cstring>
#include <iostream>
#include <thread>
#include <vector>

class MyString {
   public:
    MyString() = default;
    MyString(const char *string) {
        std::cout << "Created" << std::endl;
        m_Size = strlen(string);
        m_data = new char[m_Size];
        strcpy(m_data, string);
    }

    MyString(const MyString &myString) {
        std::cout << "Copied" << std::endl;
        m_Size = myString.m_Size;
        m_data = new char[m_Size];
        strcpy(m_data, myString.m_data);
    }

    MyString(MyString &&myString) noexcept {
        std::cout << "Moved" << std::endl;
        m_Size = myString.m_Size;
        m_data = myString.m_data;

        myString.m_data = nullptr;
        myString.m_Size = 0;
    }

    MyString &operator=(MyString &&myString) noexcept {
        std::cout << "Moved" << std::endl;

        if (this == &myString) return *this;

        delete[] m_data;
        m_Size = myString.m_Size;
        m_data = myString.m_data;

        myString.m_data = nullptr;
        myString.m_Size = 0;

        return *this;
    }

    ~MyString() {
        std::cout << "MyString Destroyed " << std::endl;
        delete[] m_data;
    }
    void Print() {
        for (uint32_t i = 0; i < m_Size; i++) {
            std::cout << m_data[i];
        }

        std::cout << std::endl;
    }

   private:
    char *m_data;
    uint32_t m_Size;
};

class Entity {
   public:
    Entity(const MyString &name) : mstring(name) {}
    Entity(MyString &&name) : mstring((MyString &&)name) {}

    void printName() { mstring.Print(); }

   private:
    MyString mstring;
};

int main(int argc, char const *argv[]) {
    // Entity entity(MyString("cherno"));

    // entity.printName();

    // MyString myString = "Hello world";
    // MyString dest((MyString &&)myString);

    // MyString dest2 = std::move(myString);

    // ------------------------------------------------

    Entity entity("cherno");
    entity.printName();

    MyString apple = "Apple";
    MyString destination;

    apple.Print();
    destination.Print();

    destination = std::move(apple);

    apple.Print();
    destination.Print();

    return 0;
}