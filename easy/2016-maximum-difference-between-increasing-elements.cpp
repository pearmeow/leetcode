/**
 * @file 2016-maximum-difference-between-increasing-elements.cpp
 * @author Perry Huang
 * @date 2025-06-16
 * 2016. Maximum Difference Between Increasing Elements
 * Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i]
 * and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].
 * Return the maximum difference. If no such i and j exists, return -1.
 */

#include <vector>

class Solution {
public:
    int maximumDifference(std::vector<int>& nums) {
        int theMin = nums[0];
        int maxDiff = -1;
        for (int num : nums) {
            if (theMin < num) {
                maxDiff = std::max(maxDiff, num - theMin);
            } else {
                theMin = num;
            }
        }
        return maxDiff;
    }
};
