#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
 
using namespace std;


class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
            int prev = nums[0];
            int next = nums[2];
            int middle = nums[1];
            int subarrays = 0;

            for (size_t i = 0; i < nums.size()-1; i++)
            {
                if(middle/2 == prev + next){
                    subarrays++;
                }
                prev = middle;
                middle = next;
                next = nums[i+1];
            }
            return subarrays;
        }  
    };


int main(int argc, char const *argv[])
{
    std::vector<int> test1 = {1,2,1,4,1};
    std::vector<int> test2 = {1,1,1};

    Solution sol;

    std::cout << "Test 1: " << sol.countSubarrays(test1) << std::endl;
    std::cout << "Test 2: "  << sol.countSubarrays(test2) << std::endl;



    return 0;
}
