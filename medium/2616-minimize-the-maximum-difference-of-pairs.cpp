/**
 * @file 2616-minimize-the-maximum-difference-of-pairs.cpp
 * @author Perry Huang
 * @date 2025-06-13
 * 2616. Minimize the Maximum Difference of Pairs
 * You are given a 0-indexed integer array nums and an integer p.
 * Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized.
 * Also, ensure no index appears more than once amongst the p pairs.
 * Note that for a pair of elements at the index i and j, the difference of this pair
 * is |nums[i] - nums[j]|, where |x| represents the absolute value of x.
 * Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.
 */

#include <vector>
#include <algorithm>

int can(const std::vector<int>& nums, int diff) {
    int res = 0;
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        if (std::abs(nums[i] - nums[i + 1]) <= diff) {
            ++res;
            ++i;
        }
    }
    return res;
}

int minimizeMax(std::vector<int>& nums, int p) {
    if (p == 0) return 0;
    std::sort(nums.begin(), nums.end());
    int low = 0;
    int high = nums[nums.size() - 1] - nums[0];
    int mid = 0;
    while (low < high) {
        mid = (high + low) / 2;
        if (can(nums, mid) >= p) { // enough pairs, so go lower
            high = mid;
        } else { // not enough pairs, so go higher
            low = mid + 1;
        }
    }
    return low;
}
