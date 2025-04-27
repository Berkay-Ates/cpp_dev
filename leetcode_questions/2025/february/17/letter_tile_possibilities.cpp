#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <thread>

using namespace std;

class Solution
{
private:
    int buildString(vector<int> freq)
    {
        int ways = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                freq[i]--;
                ways += 1 + buildString(freq);
                freq[i]++;
            }
        }
        return ways;
    }

public:
    int numTilePossibilities(string tiles)
    {
        vector<int> freq(26, 0);
        for (char c : tiles)
            freq[c - 'A']++;

        return buildString(freq);
    }
};

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    unordered_map<string, int> memo;

    int buildString(vector<int> &freq)
    {
        string key = encode(freq);
        if (memo.count(key))
            return memo[key];

        int ways = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                freq[i]--;
                ways += 1 + buildString(freq);
                freq[i]++;
            }
        }
        return memo[key] = ways;
    }

    string encode(const vector<int> &freq)
    {
        string s;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
                s += to_string(freq[i]) + ",";
        }
        return s;
    }

public:
    int numTilePossibilities(string tiles)
    {
        vector<int> freq(26, 0);
        for (char c : tiles)
            freq[c - 'A']++;

        return buildString(freq);
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;

    string case1 = "AAB";
    string case2 = "AAABBC";
    string case3 = "V";

    cout << case1 << ": " << sol.numTilePossibilities(case1) << endl;
    cout << case2 << ": " << sol.numTilePossibilities(case2) << endl;
    cout << case3 << ": " << sol.numTilePossibilities(case3) << endl;

    return 0;
}