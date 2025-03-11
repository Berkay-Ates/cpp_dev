#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

class Base {
   public:
    Base() { std::cout << "Base Constructed\n"; }
    virtual ~Base() { std::cout << "Base DeStructed\n"; }

   private:
    int baseX;
};

class Derived : public Base {
   public:
    Derived() {
        std::cout << "Derived Constructed\n";
        // baseX = 34;  // private olan bir elemana asla erisemz, public derive yada private derive
        // etse de
    }
    ~Derived() { std::cout << "Derived DeStructed\n"; }
};

int main(int argc, char const* argv[]) {
    Base* base = new Base();
    delete base;

    std::cout << "------------------------------------" << std::endl;

    Derived* derived = new Derived();
    delete derived;

    std::cout << "------------------------------------" << std::endl;

    Base* poly = new Derived();
    delete poly;

    int a = 5;
    double b = (double)a;
    double c = static_cast<double>(b) + 9;

    std::cout << a << " " << b << " " << c << std::endl;

    return 0;
}