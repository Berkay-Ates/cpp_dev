#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class ProductOfNumbers
{
    vector<int> stream = {1};
    int n;
    int last_zero_idx;

public:
    ProductOfNumbers()
    {
        n = 1;
        last_zero_idx = -1;
    }

    void add(int num)
    {
        if (num == 0)
            last_zero_idx = n;

        if (stream.back() == 0)
            stream.push_back(num);
        else
            stream.push_back(stream.back() * num);

        n++;
    }

    int getProduct(int k)
    {
        if (last_zero_idx >= n - k)
            return 0;
        if (stream[n - k - 1] == 0)
            return stream[n - 1];
        else
            return stream[n - 1] / stream[n - k - 1];
    }
};

int main(int argc, char const *argv[])
{
    ProductOfNumbers productOfNumbers;

    productOfNumbers.add(3);
    productOfNumbers.add(0);
    productOfNumbers.add(2);
    productOfNumbers.add(5);
    productOfNumbers.add(4);

    cout << productOfNumbers.getProduct(2) << endl;
    cout << productOfNumbers.getProduct(3) << endl;
    cout << productOfNumbers.getProduct(4) << endl;

    productOfNumbers.add(8);

    cout << productOfNumbers.getProduct(2) << endl;

    return 0;
}