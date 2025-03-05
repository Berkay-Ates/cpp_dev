#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <stack>
#include <thread>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(const string &s)
    {
        stack<int> st;
        st.push(-1);

        int maxLen = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);

            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    int length = i - st.top();
                    maxLen = max(maxLen, length);
                }
            }
        }

        return maxLen;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    string case1 = "(()";
    string case2 = ")()())";
    string case3 = "";
    string case4 = "()(())";

    cout << sol.longestValidParentheses(case4) << endl;
    // cout << sol.longestValidParentheses(case2) << endl;
    // cout << sol.longestValidParentheses(case3) << endl;

    return 0;
}