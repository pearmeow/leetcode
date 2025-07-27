/**
 * @file 53-maximum-subarray.cpp
 * @author Perry Huang
 * @date 2025-05-28
 * 53. Maximum Subarray
 * Given an integer array nums, find the subarray with the largest sum, and return its sum.
 */

#include <vector>

class Solution {
   public:
    int maxSubArray(std::vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int curr = 0;
        int maxSub = nums[0];
        for (size_t i = 0; i < nums.size(); ++i) {
            curr += nums[i];
            maxSub = std::max(curr, maxSub);
            if (curr < 0) curr = 0;
        }
        return maxSub;
    }
};
