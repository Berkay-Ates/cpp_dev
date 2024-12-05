#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canChange(string start, string target)
    {
        string stringStart = "";
        string stringTarget = "";

        int sLStart = INT_MAX;
        int sLEnd = INT_MIN;

        int sRStart = INT_MAX;
        int sREnd = INT_MIN;

        int tLStart = INT_MAX;
        int tLEnd = INT_MIN;

        int tRStart = INT_MAX;
        int tREnd = INT_MIN;

        for (int i = 0; i < (int)start.size(); i++)
        {
            if (start[i] == 'L')
            {
                if (i < sLStart)
                    sLStart = i;

                if (i > sLEnd)
                    sLEnd = i;
            }
            else if (start[i] == 'R')
            {
                if (i < sRStart)
                    sRStart = i;

                if (i > sREnd)
                    sREnd = i;
            }
        }

        for (int i = 0; i < (int)target.size(); i++)
        {
            if (target[i] == 'L')
            {
                if (i < tLStart)
                    tLStart = i;

                if (i > tLEnd)
                    tLEnd = i;
            }
            else if (target[i] == 'R')
            {
                if (i < tRStart)
                    tRStart = i;

                if (i > tREnd)
                    tREnd = i;
            }
        }

        if (sLStart < tLStart)
            return false;

        if (sLEnd < tLEnd)
            return false;

        if (sRStart > tRStart)
            return false;

        if (sREnd > tREnd)
            return false;

        for (int i = 0; i < (int)start.size(); i++)
        {
            if (start[i] != '_')
                stringStart += start[i];

            if (target[i] != '_')
                stringTarget += target[i];
        }
        return stringStart == stringTarget;
    }
};

int main(int argc, char const *argv[])
{

    Solution sol;

    string start1 = "_L__R__R_";
    string target1 = "L______RR";

    string start2 = "R_L_";
    string target2 = "__LR";

    string start3 = "_R";
    string target3 = "R_";

    cout << sol.canChange(start1, target1) << endl;
    cout << sol.canChange(start2, target2) << endl;
    cout << sol.canChange(start3, target3) << endl;

    return 0;
}