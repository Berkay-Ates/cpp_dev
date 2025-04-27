#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <unordered_map>

using namespace std;

class Solution
{
    unordered_map<int, vector<int>> values;
    int digitSums = 0;
    int maxSummation = -1;

    int digitSummation(int number)
    {
        int sum = 0;
        while (number > 0)
        {
            sum += number % 10;
            number = number / 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            digitSums = digitSummation(nums[i]);

            if (values[digitSums].size() == 0)
            {
                values[digitSums].push_back(nums[i]);
                values[digitSums].push_back(-1);
            }
            else
            {
                if (values[digitSums][1] < nums[i])
                    if (values[digitSums][1] > values[digitSums][0])
                        values[digitSums][0] = nums[i];
                    else
                        values[digitSums][1] = nums[i];

                else if (values[digitSums][0] < nums[i])
                    if (values[digitSums][0] > values[digitSums][1])
                        values[digitSums][1] = nums[i];
                    else
                        values[digitSums][0] = nums[i];
            }
        }

        for (auto value : values)
        {
            if (value.second[1] > 0 && maxSummation < value.second[0] + value.second[1])
                maxSummation = value.second[0] + value.second[1];
        }

        return maxSummation;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol1;
    vector<int> case1 = {18, 43, 36, 13, 7};
    Solution sol2;
    vector<int> case2 = {10, 12, 19, 14};

    cout << sol1.maximumSum(case1) << endl;
    cout << sol2.maximumSum(case2) << endl;

    return 0;
}