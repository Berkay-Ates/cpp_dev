#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <cctype>
#include <string>

using namespace std;
class Solution
{

public:
    string clearDigits(string s)
    {
        int i = 0;
        int j = 0;
        while (s[i] != '\0')
        {
            if (isdigit(s[i]))
            {
                s.erase(i, 1);

                j = i - 1;
                while (j > 0 && isdigit(s[j]))
                    j--;

                if (j >= 0)
                    s.erase(j, 1);

                i--;
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
    string case1 = "abc";
    string case2 = "cb34";

    cout << sol.clearDigits(case1) << endl;
    cout << sol.clearDigits(case2) << endl;

    return 0;
}