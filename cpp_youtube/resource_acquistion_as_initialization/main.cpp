#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Collection
{
public:
    Collection()
    {
        data = new int[10];
    }

    ~Collection()
    {
        delete[] data;
    };

    int &operator[](size_t index)
    {
        return data[index];
    };

    const int &operator[](size_t idx) const
    {
        return data[idx];
    }

private:
    int *data;
};

int main(int argc, char const *argv[])
{

    Collection collection;
    collection[0] = 7;
    collection[4] = 7;
    collection[3] = 7;
    collection[2] = 7;
    collection[1] = 7;

    return 0;
}