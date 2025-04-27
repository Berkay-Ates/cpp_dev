#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <queue>

using namespace std;

class Solution
{
#define ll long long

public:
    int minOperations(vector<int> &nums, int k)
    {
        priority_queue<ll, vector<ll>, greater<ll>> minheap(nums.begin(), nums.end());
        int count = 0;
        while (!minheap.empty())
        {
            ll min1 = minheap.top();
            minheap.pop();
            if (min1 >= k)
                break;

            ll min2 = minheap.top();
            minheap.pop();

            minheap.push(2 * min(min1, min2) + max(min1, min2));
            count++;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<int> case1 = {2, 11, 10, 1, 3};
    int case1K = 10;
    vector<int> case2 = {1, 1, 2, 4, 9};
    int case2K = 20;

    cout << sol.minOperations(case1, case1K) << endl;
    cout << sol.minOperations(case2, case2K) << endl;

    return 0;
}