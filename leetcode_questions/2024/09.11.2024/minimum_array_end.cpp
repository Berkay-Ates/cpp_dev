#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    Solution()
    {
    }

    ~Solution() {}

    vector<int> getBinary(int n)
    {
        vector<int> binaryRep;
        while (n)
        {
            if (n & 1)
                binaryRep.push_back(1);
            else
                binaryRep.push_back(0);
            n >>= 1;
        }
        return binaryRep;
    }

    long long minEnd(int n, int x)
    {
        if (n == 1)
            return x;

        // step1 record zero positions
        vector<int> zeroPositions;
        int count = 0;
        int val = x;
        while (val)
        {
            if ((val & 1) == 0)
                zeroPositions.push_back(count);
            count++;
            val >>= 1;
        }

        // step2 find number of bits to make n combinations
        int reqBits = ceil(log2(n));

        // step3 append more bits in zero-pos as per requirement
        for (int i = zeroPositions.size(); i < reqBits; i++)
            zeroPositions.push_back(count++);

        // step4 find bits to be appended
        vector<int> appendBits = this->getBinary(n - 1);

        // step5 form the answer
        long long answer = x;
        int pos = appendBits.size();
        while (pos--)
        {
            if (appendBits.back() == 1)
            {
                cout << "appen_bits: " << appendBits[pos] << endl;
                answer += pow(2, zeroPositions[pos]) * appendBits[pos];
            }
        }
        return answer;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.minEnd(3, 4) << endl;

    return 0;
}