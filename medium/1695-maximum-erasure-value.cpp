/**
 * @file 1695-maximum-erasure-value.cpp
 * @author Perry Huang
 * @date 2025-07-21
 * 1695. Maximum Erasure Value
 * You are given an array of positive integers nums and want to erase a subarray containing unique elements. The
 * score you get by erasing the subarray is equal to the sum of its elements. Return the maximum score you can get
 * by erasing exactly one subarray. An array b is called to be a subarray of a if it forms a contiguous subsequence
 * of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
 */

#include <unordered_map>
#include <vector>

class Solution {
   public:
    int maximumUniqueSubarray(const std::vector<int>& nums) {
        std::unordered_map<int, size_t> num_index;
        std::vector<int> prefix_sums(nums.size(), 0);
        size_t right = 0;
        size_t left = 0;
        int res = 0;
        int sum = 0;
        while (right < nums.size()) {
            if (right != 0) {
                prefix_sums[right] = prefix_sums[right - 1] + nums[right];
            } else {
                prefix_sums[right] = nums[right];
            }
            if (num_index.find(nums[right]) != num_index.end()) {
                if (num_index[nums[right]] >= left) {
                    res = std::max(res, sum - prefix_sums[left] + nums[left]);
                    left = num_index[nums[right]] + 1;
                }
            }
            num_index[nums[right]] = right;
            sum += nums[right];
            ++right;
        }
        res = std::max(res, sum - prefix_sums[left] + nums[left]);
        return res;
    }
};
