#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    int maximumCount(std::vector<int>& nums) {
        return std::max(
            static_cast<int>(std::lower_bound(nums.begin(), nums.end(), 0) - nums.begin()),
            static_cast<int>(nums.size() -
                             (std::upper_bound(nums.begin(), nums.end(), 0) - nums.begin())));
    }
};

int main(int argc, char const* argv[]) { return 0; }