
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

class Solution
{
public:
    bool checkPowersOfThree(const int n)
    {
        int curr = n;
        static const int base = 3;
        while (curr)
        {
            const int rem = curr % base;
            if (rem > 1)
                return false;
            curr /= base;
        }
        return true;
    }
};

using namespace std;
s int main(int argc, char cont *argv[])
{
    int const number = 12;

    Solution sol;

    cout << sol.checkPowersOfThree(number) << endl;

    return 0;
}