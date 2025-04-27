#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

class Solution
{

private:
    int shortestPath(vector<vector<int>> &adj, int n)
    {
        queue<int> q;
        q.push(0);

        vector<bool> visited(n);
        visited[0] = true;
        int distance = 0;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                if (curr == n - 1)
                    return distance;

                for (int adjacent : adj[curr])
                {
                    if (!visited[adjacent])
                    {
                        visited[adjacent] = true;
                        q.push(adjacent);
                    }
                }
            }
            distance++;
        }

        return distance;
    }

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++)
            adj[i].push_back(i + 1);

        // iota(adj.begin(), adj.end() - 1, 1);

        // DAG
        vector<int> res;
        for (auto &query : queries)
        {
            adj[query[0]].push_back(query[1]);
            res.push_back(shortestPath(adj, n));
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    int n1 = 5;
    vector<vector<int>> path1 = {{2, 4}, {0, 2}, {0, 4}};

    int n2 = 4;
    vector<vector<int>> path2 = {{0, 3}, {0, 2}};

    int n3 = 6;
    vector<vector<int>> path3 = {{1, 4}, {0, 2}};

    vector<int> result = sol.shortestDistanceAfterQueries(n1, path1);

    cout << "result is: " << endl;
    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << result.at(i) << ", ";
    }
    cout << endl;

    return 0;
}