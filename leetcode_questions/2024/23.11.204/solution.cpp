#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution2
{
public:
    vector<vector<char>> rotateTheBox2(vector<vector<char>> &box)
    {
        int tmpI = 0;
        int tmpJ = 0;

        int m = box.size(), n = box[0].size();
        vector<vector<char>> temp(n, vector<char>(m));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                temp[j][m - i - 1] = box[i][j];
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cout << temp[i][j] << " ";
            }
            cout << endl; // Her satırdan sonra yeni bir satıra geçmek için
        }

        cout << "-before rotation" << endl;

        for (int i = n - 1; ~i; i--)
        {
            for (int j = 0; j < m; j++)
            {
                if (temp[i][j] == '#')
                {
                    tmpI = i + 1;
                    tmpJ = j;
                    while (tmpI < n && temp.at(tmpI).at(tmpJ) == '.')
                    {
                        tmpI++;
                    }
                    temp[i][j] = '.';
                    temp.at(tmpI - 1).at(tmpJ) = '#';
                }
            }
        }
        return temp;
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        // # -> kaya
        // * -> engel
        // . -> bos

        int m = box.size();
        int n = box.at(0).size();
        int tmpI = 0;
        int tmpJ = 0;

        vector<vector<char>> temp(n, vector<char>(m, '.'));

        cout << "M: " << m << " N: " << n << endl;

        for (int i = 0; i < m; i++)
        {
            for (int j = n - 1; ~j; j--)
            {
                if (box.at(i).at(j) == '*')
                {
                    temp.at(j).at(i) = '*';
                }
                else if (box.at(i).at(j) == '#')
                {
                    tmpI = i;
                    tmpJ = j;
                    while (temp.at(tmpJ).at(tmpI) == '.' && tmpJ < m)
                    {
                        tmpJ++;
                    }
                    temp.at(tmpJ - 1).at(tmpI) = '#';
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                printf(" %c ", temp[i][j]);
            }
            cout << endl; // Her satırdan sonra yeni bir satıra geçmek için
        }
        return temp;
    }
};

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        for (int j = 0; j < m; ++j)
        {
            queue<int> q;
            for (int i = n - 1; ~i; --i)
            {
                if (ans[i][j] == '*')
                {
                    queue<int> t;
                    swap(t, q);
                }
                else if (ans[i][j] == '.')
                {
                    q.push(i);
                }
                else if (!q.empty())
                {
                    ans[q.front()][j] = '#';
                    q.pop();
                    ans[i][j] = '.';
                    q.push(i);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> exmp1 = {{'#', '.', '#'}};
    vector<vector<char>> exmp2 = {{'#', '.', '*', '.'}, {'#', '#', '*', '.'}};
    Solution2 sol;

    exmp1 = sol.rotateTheBox2(exmp2);

    return 0;
}