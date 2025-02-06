#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;

        vector<int> diff;
        int i = 0;
        while (i < s1.length() && diff.size() <= 2)
        {
            if (s1.at(i) != s2.at(i))
                diff.push_back(i);
            i++;
        }

        if (diff.size() == 0)
            return true;

        if (diff.size() == 2)
        {
            if (s1.at(diff.at(0)) == s2.at(diff.at(1)) && s1.at(diff.at(1)) == s2.at(diff.at(0)))
                return true;
        }

        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<string> case1 = {"bank", "kanb"};
    vector<string> case2 = {"attack", "defend"};
    vector<string> case3 = {"kelb", "kelb"};

    cout << sol.areAlmostEqual(case1.at(0), case1.at(1)) << endl;
    cout << sol.areAlmostEqual(case2.at(0), case2.at(1)) << endl;
    cout << sol.areAlmostEqual(case3.at(0), case3.at(1)) << endl;
    return 0;
}