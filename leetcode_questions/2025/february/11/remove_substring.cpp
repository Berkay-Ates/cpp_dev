#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        int i = 0;
        int j = 0;
        while (s[i] != '\0')
        {
            if (s[i] == part[0])
            {
                j = 0;
                while (part[j] != '\0' && s[j + i] == part[j])
                    j++;

                if (part[j] == '\0')
                {
                    s.erase(i, j);
                    i -= part.size();
                    if (i < 0)
                        i = 0;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    string case1 = "daabcbaabcbc";
    string part1 = "abc";

    string case2 = "axxxxyyyyb";
    string part2 = "xy";

    string case3 = "ccctltltlb";
    string part3 = "ctl";

    cout << sol.removeOccurrences(case1, part1) << endl;
    cout << sol.removeOccurrences(case2, part2) << endl;
    cout << sol.removeOccurrences(case3, part3) << endl;

    return 0;
}