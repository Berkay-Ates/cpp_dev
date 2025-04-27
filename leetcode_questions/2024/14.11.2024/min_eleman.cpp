#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int i = 0;
        int tour = 0;

        for (int i = 0; i < (int)quantities.size(); i++)
        {
            tour += quantities.at(i);
            cout << i << endl;
        }
        int res = (int)(tour / (quantities.size()));
        res += tour - res * quantities.size();
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 6;
    vector<int> quantities = {11, 6};
    cout << sol.minimizedMaximum(n, quantities) << endl;

    return 0;
}
