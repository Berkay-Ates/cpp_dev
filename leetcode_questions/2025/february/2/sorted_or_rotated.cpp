#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;
class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0; // Count number of times nums[i] > nums[i+1]
        int n = (int)nums.size();

        // Check how many times the array breaks ascending order
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > nums[(i + 1) % n])
                count++;
        }

        // A valid rotated sorted array can have at most one break
        return count <= 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> case1 = {3, 4, 5, 1, 2};
    vector<int> case2 = {2, 1, 3, 4};
    vector<int> case3 = {1, 2, 3};

    cout << sol.check(case1) << endl;
    cout << sol.check(case2) << endl;
    cout << sol.check(case3) << endl;

    return 0;
}