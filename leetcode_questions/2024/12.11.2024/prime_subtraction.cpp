#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPrime(int number)
    {
        if (number <= 1) // Negatif sayılar ve 1 asal değil
            return false;
        if (number == 2) // 2 asal bir sayıdır
            return true;
        if (number % 2 == 0) // 2'den büyük çift sayılar asal değildir
            return false;

        for (int j = 3; j * j <= number; j += 2) // Sadece tek sayılarla kontrol
        {
            if (number % j == 0)
                return false;
        }

        return true;
    }

    int nextPrime(int number)
    {
        number = number + 1;
        while (!this->isPrime(number))
        {
            number += 1;
        }

        return number;
    }

    bool primeSubOperation(vector<int> &nums)
    {

        int i = 0;
        int j = 0;
        for (int i = (int)nums.size() - 1; 0 < i; i--)
        {

            if (i > 0 && nums.at(i) <= nums.at(i - 1))
            {
                j = nums.at(i - 1) - nums.at(i);
                while (nums.at(i) <= nums.at(i - 1))
                {
                    j = this->nextPrime(j);
                    nums[i - 1] -= j;

                    if (nums.at(i - 1) <= 0)
                        return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    vector<int> vector1 = {4, 9, 6, 10};
    vector<int> vector2 = {6, 8, 11, 12};
    vector<int> vector3 = {5, 8, 3};
    vector<int> vector4 = {998, 2};
    vector<int> vector5 = {18, 15, 13, 9};
    vector<int> vector6 = {3, 4, 10, 15, 6};

    Solution sol;
    cout << "vector1: " << endl
         << sol.primeSubOperation(vector1) << endl;
    cout << "vector2: " << endl
         << sol.primeSubOperation(vector2) << endl;
    cout << "vector3: " << endl
         << sol.primeSubOperation(vector3) << endl;
    cout << "vector4: " << endl
         << sol.primeSubOperation(vector4) << endl;
    cout << "vector5: " << endl
         << sol.primeSubOperation(vector5) << endl;
    cout << "vector6: " << endl
         << sol.primeSubOperation(vector6) << endl;

    return 0;
}