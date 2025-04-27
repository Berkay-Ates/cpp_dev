#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
    bool isSameParity(int num1, int num2)
    {
        if (num1 % 2 == num2 % 2)
            return true;

        return false;
    }

public:
    bool isArraySpecial(vector<int> &nums)
    {
        int i = 1;

        while (i < nums.size() and !isSameParity(nums[i - 1], nums[i]))
            i++;

        if (i == nums.size())
            return true;

        return false;
    }
};

int main()
{
    Solution sol;

    vector<int> case1 = {1};
    vector<int> case2 = {2, 1, 4};
    vector<int> case3 = {4, 3, 1, 6};

    cout << sol.isArraySpecial(case1) << endl;
    cout << sol.isArraySpecial(case2) << endl;
    cout << sol.isArraySpecial(case3) << endl;

    return 0;
}