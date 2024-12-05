#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> referencePath(n);
        vector<int> answer(queries.size());
        int shortestPath = 0;
        int j = 0;

        // std::iota fonksiyonu ile referenceCount vektörünü 0, 1, 2, ..., n-1 ile doldur
        iota(referencePath.begin(), referencePath.end(), 1);
        for (int i = 0; i < (int)referencePath.size(); i++)
        {
            cout << referencePath.at(i) << ", ";
        }
        cout << endl;

        for (int i = 0; i < (int)queries.size(); i++)
        {
            if (referencePath[queries.at(i).at(0)] < queries.at(i).at(1))
                referencePath[queries.at(i).at(0)] = queries.at(i).at(1);

            shortestPath = 1;
            j = 0;

            for (int i = 0; i < (int)referencePath.size(); i++)
            {
                cout << referencePath.at(i) << ", ";
            }
            cout << endl;

            while (referencePath[j] < n - 1)
            {
                shortestPath++;
                j = referencePath[j];
            }
            answer.at(i) = shortestPath;
        }
        return answer;
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

    vector<int> result = sol.shortestDistanceAfterQueries(n3, path3);

    cout << "result is: " << endl;
    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << result.at(i) << ", ";
    }
    cout << endl;

    return 0;
}