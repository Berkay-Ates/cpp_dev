#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int countSubarrays(vector<int>& nums) {
        if (nums.size() < 3) return 0;

        int subarrays = 0;

        for (size_t i = 1; i < nums.size()-1; i++) {
            if ( nums[i] / 2.0 ==  nums[i-1] + nums[i+1]) {
                subarrays++;
            }
        }

        return subarrays;
    }
};

int main(int argc, char const* argv[]) {
    std::vector<int> test1 = {1, 2, 1, 4, 1};
    std::vector<int> test2 = {-1,-4,-1,4};

    Solution sol;

    std::cout << "Test 1: " << sol.countSubarrays(test1) << std::endl;
    std::cout << "Test 2: " << sol.countSubarrays(test2) << std::endl;

    return 0;
}
