#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        unordered_map<int, int> itemColor;
        unordered_map<int, int> colorFreq;
        int prevColor = 0;
        vector<int> colorCount;
        int count = 0;
        for (int i = 0; i < (int)queries.size(); i++)
        {
            if (itemColor.count(queries[i][0]))
            {
                prevColor = itemColor[queries[i][0]];
                itemColor[queries[i][0]] = queries[i][1];
                colorFreq[queries[i][1]]++;
                colorFreq[prevColor]--;

                if (colorFreq[prevColor] == 0)
                    colorFreq.erase(prevColor);
            }
            else
            {
                itemColor[queries[i][0]] = queries[i][1];
                colorFreq[queries[i][1]]++;
            }

            colorCount.push_back(colorFreq.size());
        }
        return colorCount;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> case1 = {{1, 4}, {2, 5}, {1, 3}, {3, 4}};
    vector<vector<int>> case2 = {{0, 1}, {1, 2}, {2, 2}, {3, 4}, {4, 5}};

    vector<int> output;
    output = sol.queryResults(case1.size(), case1);

    for (int i = 0; i < output.size(); i++)
        cout << output[i] << endl;

    cout << " " << endl;
    output = sol.queryResults(case2.size(), case2);

    for (int i = 0; i < output.size(); i++)
        cout << output[i] << endl;

    return 0;
}