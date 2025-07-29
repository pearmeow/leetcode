/**
 * @file 3487-maximum-unique-subarray-sum-after-deletion.cpp
 * @author Perry Huang
 * @date 2025-07-24
 * 3487. Maximum Unique Subarray Sum After Deletion
 * You are given an integer array nums.
 * You are allowed to delete any number of elements from nums without making it empty. After performing the
 * deletions, select a subarray of nums such that: All elements in the subarray are unique. The sum of the elements
 * in the subarray is maximized. Return the maximum sum of such a subarray.
 */

#include <unordered_set>
#include <vector>

class Solution {
public:
    int maxSum(const std::vector<int>& nums) {
        int most = nums[0];
        int sum = 0;
        std::unordered_set<int> found;
        for (int i : nums) {
            if (found.find(i) == found.end()) {
                found.insert(i);
                if (i > 0) {
                    sum += i;
                }
                most = std::max(most, i);
            }
        }
        if (most < 0) {
            return most;
        }
        return sum;
    }
};
