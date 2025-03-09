#include <iostream>

void Print(int value) { std::cout << value << std::endl; }
void Print(std::string value) { std::cout << value << std::endl; }

template <typename T>
void genericPrint(T value) {
    std::cout << value << std::endl;
}

template <long long N>
class Array {
   private:
    long double m_Array[N];

   public:
    int GetSize() const { return N; }
};

template <typename T, int N>
class GenericClass {
   private:
    T m_array[N];

   public:
    int getSize() const { return N; }
    void printTypeName() const { std::cout << "T" << std::endl; }
};

int main() {
    Print(5);
    Print("Hello");

    genericPrint("90909090");
    genericPrint(88989898);

    Array<99> arr;
    genericPrint(arr.GetSize());

    GenericClass<double, 10> generic;
    genericPrint(generic.getSize());
    generic.printTypeName();

    std::cin.get();
}