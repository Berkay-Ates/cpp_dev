

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
 
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int> multiplyMaps;
        int totalPairs=0;

        for (int i = 0; i < (int) nums.size(); i++)
        {
            for (int j = 0; j < (int) nums.size(); j++)
                multiplyMaps[nums.at(i)*nums.at(j)]+=1;
        }


        int pairsElements = 0;
        for(const auto& pair: multiplyMaps){
            if (pair.second >= 4){
                pairsElements = pair.second/2;
                totalPairs += 8*((pairsElements) * (pairsElements-1))/2;
            }
        }
        return totalPairs;
    }
};
 
int main(int argc, char const *argv[])
{
    Solution sol;

    vector<int> case1 = {2,3,4,6};
    vector<int> case2 = {1,2,4,5,10};
    vector<int> case3 = {2,3,4,6,8,12};

    cout << sol.tupleSameProduct(case1) << endl;
    cout << sol.tupleSameProduct(case2) << endl;
    cout << sol.tupleSameProduct(case3) << endl;

    return 0;
}