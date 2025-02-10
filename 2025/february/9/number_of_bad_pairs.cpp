#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        unordered_map<int, long long> freq;
        long long totalPairs = 1LL * nums.size() * (nums.size() - 1) / 2;
        long long matchingPairs = 0;

        for (int i = 0; i < (int)nums.size(); i++)
        {
            matchingPairs += freq[i - nums[i]];
            freq[i - nums[i]]++;
        }

        return totalPairs - matchingPairs;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}