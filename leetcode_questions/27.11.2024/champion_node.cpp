#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int findChampion(int n, vector<vector<int>> &edges)
    {
        vector<int> referenceCount(n, 0);
        int winner = -1;

        for (int i = 0; i < (int)edges.size(); i++)
            referenceCount[edges.at(i).at(1)]++;

        for (int i = 0; i < n; i++)
        {
            if (referenceCount[i] == 0 && winner != -1)
                return -1;

            if (referenceCount[i] == 0)
                winner = i;
        }

        return winner;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> case1 = {{0, 1}, {1, 2}};
    int case1N = 3;
    vector<vector<int>> case2 = {{0, 2}, {1, 3}, {1, 2}};
    int case2N = 4;

    Solution sol;

    cout << "Case1: " << sol.findChampion(case1N, case1) << endl;
    cout << "Case2: " << sol.findChampion(case2N, case2) << endl;

    return 0;
}