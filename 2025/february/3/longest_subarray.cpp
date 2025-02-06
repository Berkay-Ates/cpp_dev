#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;
class Solution
{
public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int longest_inc = 1;
        int longest_dec = 1;

        int temp = 0;
        int j = 1;
        int i = 1;
        while (i < nums.size())
        {
            if (nums.at(i - 1) < nums.at(i))
            {
                j = i;
                while (j < nums.size() && nums.at(j - 1) < nums.at(j))
                    j++;

                j = (j - i) + 1;
                if (j > longest_inc)
                    longest_inc = j;
            }

            if (nums.at(i - 1) > nums.at(i))
            {
                j = i;
                while (j < nums.size() && nums.at(j - 1) > nums.at(j))
                    j++;

                j = (j - i) + 1;
                if (j > longest_dec)
                    longest_dec = j;
            }

            i++;
        }
        return longest_dec > longest_inc ? longest_dec : longest_inc;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> case1 = {1, 4, 3, 3, 2};
    vector<int> case2 = {3, 3, 3, 3};
    vector<int> case3 = {3, 2, 1};

    cout << sol.longestMonotonicSubarray(case1) << endl;
    cout << sol.longestMonotonicSubarray(case2) << endl;
    cout << sol.longestMonotonicSubarray(case3) << endl;

    return 0;
}