#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <thread>
#include <vector>

class Solution {
   public:
    int numberOfSubstrings(std::string s) {
        int n = s.size();
        int subarray = 0;
        std::vector<int> freq(3, 0);
        int left = 0, right = 0;

        while (n > right) {
            freq[s[right] - 'a']++;
            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                subarray += n - right;
                freq[s[left] - 'a']--;
                left++;
            }
            right++;
        }
        return subarray;
    }

   private:
};

int main(int argc, char const *argv[]) { return 0; }