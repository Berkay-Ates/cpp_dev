#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
    set<int> nodes;
    map<int, vector<int>> adj;
    map<int, int> outDegree, inDegree;
    vector<int> eulerPath;

    void findEulerPath(int currNode)
    {
        int nextNode;
        while (outDegree[currNode])
        {
            nextNode = adj[currNode][outDegree[currNode] - 1];
            outDegree[currNode]--;
            findEulerPath(nextNode);
        }
        eulerPath.push_back(currNode);
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        //* Build and adj-list
        for (auto pair : pairs)
        {
            adj[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
            nodes.insert(pair[0]);
            nodes.insert(pair[1]);
        }

        //* Find starting node for euler path
        int startingNode = INT_MAX;
        for (int node : nodes)
        {
            if (outDegree[node] == 1 + inDegree[node])
            {
                startingNode = node;
                break;
            }
        }

        if (startingNode == INT_MAX)
            startingNode = pairs[0][0]; // there is eulerian circuit exists

        // Find euler path
        findEulerPath(startingNode);

        // return euler path
        reverse(eulerPath.begin(), eulerPath.end());
        vector<vector<int>> ans;
        for (int i = 1; i < (int)eulerPath.size(); i++)
            ans.push_back({eulerPath[i - 1], eulerPath[i]});

        return ans;
    }
};

int main(int argc, char const *argv[])
{

    Solution sol;

    vector<vector<int>> example = {{5, 1}, {4, 5}, {11, 9}, {9, 4}};
    vector<vector<int>> example2 = {{1, 3}, {3, 2}, {2, 1}};
    vector<vector<int>> example3 = {{1, 2}, {1, 3}, {2, 1}};

    vector<vector<int>> result = sol.validArrangement(example);

    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << "[" << result.at(i).at(0) << "," << result.at(i).at(1) << "]";
    }

    return 0;
}