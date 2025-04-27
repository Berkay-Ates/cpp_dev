#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int black = 0;
        int min_recoloring = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (blocks[i] == 'B') black++;
            if (i >= k - 1) {
                min_recoloring = min(k - black, min_recoloring);
                if (blocks[i - k + 1] == 'B') black--;
            }
        }
        return min_recoloring;
    }
};

class Solution {
   public:
    int minimumRecolors(string blocks, int k) {
        int const n = blocks.size();
        int blacks = 0;
        int min_recoloring = INTMAX_MAX;

        for (int i = 0; i < n; i++) {
            if (blocks[i] == 'B') blacks++;
            if (i >= k + 1) {
                min_recoloring = min(k - blacks, min_recoloring);
                if (blocks[i - k + 1] == 'B') {
                    blacks--;
                }
            }
        }
        return min_recoloring;
    }
};

int main(int argc, char const *argv[]) { return 0; }