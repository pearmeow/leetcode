/**
 * @file 300-longest-increasing-subsequence.cpp
 * @author Perry Huang
 * @date 2024-10-12
 * 300. Longest Increasing Subsequence
 * Given an integer array nums, return the length
 * of the longest strictly increasing subsequence.
 */

#include <vector>

int lengthOfLIS(const std::vector<int>& nums) {
    std::vector<int> dp(nums.size(), 1);
    int curr = 0;
    for (size_t i = nums.size(); i > 0; --i) {
        curr = nums[i - 1];
        for (size_t j = i; j < nums.size(); ++j) {
            if (curr < nums[j]) {
                dp[i - 1] = std::max(dp[i - 1], 1 + dp[j]);
            }
        }
    }
    int longestSub = 0;
    for (size_t i = 0; i < dp.size(); ++i) {
        longestSub = std::max(longestSub, dp[i]);
    }
    return longestSub;
}
