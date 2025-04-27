#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>

class Solution {
   public:
    int longestNiceSubarray(std::vector<int>& nums) {
        const int n = nums.size();
        int left = 0;
        int right = 0;

        int max_window_size = 0;
        int xor_sum = 0;
        int curr_sum = 0;

        while (right < n) {
            curr_sum += nums[right];
            xor_sum ^= nums[right];

            while (xor_sum != curr_sum) {
                curr_sum -= nums[left];
                xor_sum -= nums[left];
                left++;
            }
            max_window_size = std::max(max_window_size, right - left + 1);
            right++;
        }
        return max_window_size;
    }
};

int main(int argc, char const* argv[]) { return 0; }