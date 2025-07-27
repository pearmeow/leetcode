/**
 * @file 2294-partition-array-such-that-maximum-difference-is-k.cpp
 * @author Perry Huang
 * @date 2025-06-18
 * 2294. Partition Array Such That Maximum Difference Is K
 * You are given an integer array nums and an integer k. You may partition nums into one or more subsequences such that each element in nums appears in exactly one of the subsequences.
 * Return the minimum number of subsequences needed such that the difference between the maximum and minimum values in each subsequence is at most k.
 * A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
 */

#include <algorithm>
#include <vector>

class Solution {
   public:
    int partitionArray(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        size_t least = nums[0];
        size_t partitions = 1;
        for (int i : nums) {
            if (i - least > k) {
                least = i;
                ++partitions;
            }
        }
        return partitions;
    }
};
