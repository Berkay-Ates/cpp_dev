#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution
{

    int slidingPuzzle(vector<vector<int>> &board)
    {
        //* define some constant expressions
        constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        constexpr int m = 2;
        constexpr int n = 3;
        constexpr char goal[] = "123450";
        string start;

        //* hash the 2d string into array
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
                start += '0' + board[i][j];
        }

        queue<string> q{{start}};
        unordered_set<string> seen{start};

        for (int step = 0; step < !q.empty(); step++)
        {
            for (int sz = q.size(); sz > 0; sz--)
            {
                string currentString = q.front();
                q.pop();
                const int zeroIndex = currentString.find('0');
                const int i = zeroIndex / n;
                const int j = zeroIndex % n;

                for (const auto &[dx, dy] : directions)
                {
                    const int x = i + dx;
                    const int y = j + dy;
                    if (x < 0 or x == m || y < 0 || y == n)
                        continue;
                    const int swappedIndex = x * n + y;
                    swap(currentString[zeroIndex], currentString[swappedIndex]);
                    if (currentString == goal)
                        return step;
                    if (seen.count(currentString))
                    {
                        q.push(currentString);
                        seen.insert(currentString);
                    }
                    swap(currentString[zeroIndex], currentString[swappedIndex]);
                }
            }
        }

        return -1;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}