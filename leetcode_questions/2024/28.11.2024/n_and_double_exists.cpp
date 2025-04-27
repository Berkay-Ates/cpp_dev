#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> seen_numbers;
        for (int ele : arr)
        {
            if (seen_numbers.count(2 * ele) or (ele % 2 == 0 and seen_numbers.count(ele / 2)))
                return true;

            seen_numbers.insert(ele);
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> case1 = {5, 2, 10, 3};
    vector<int> case2 = {3, 1, 7, 11};

    cout << sol.checkIfExist(case1) << endl;
    cout << sol.checkIfExist(case2) << endl;

    return 0;
}