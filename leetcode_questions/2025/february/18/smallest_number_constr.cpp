#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>
#include <stack>

using namespace std;

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        int n = pattern.size();
        stack<int> st;
        string res = "";

        for (int i = 1; i <= n + 1; i++)
        {
            st.push(i);
            char c = pattern[i - 1];

            if (i == n + 1 or c == 'I')
            {
                while (!st.empty())
                {
                    res.push_back(char('0' + st.top()));
                    st.pop();
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}