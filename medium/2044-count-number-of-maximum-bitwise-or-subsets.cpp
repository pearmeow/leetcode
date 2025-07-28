/**
 * @file 2044-count-number-of-maximum-bitwise-or-subsets.cpp
 * @author Perry Huang
 * @date 2025-07-27
 * 2044. Count Number of Maximum Bitwise-OR Subsets
 * Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of
 * different non-empty subsets with the maximum bitwise OR. An array a is a subset of an array b if a can be
 * obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the
 * indices of the elements chosen are different. The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR
 * a[a.length - 1] (0-indexed).
 */

#include <vector>

class Solution {
public:
    int countMaxOrSubsets(const std::vector<int>& nums) {
        int target = 0;
        for (int i : nums) {
            target |= i;
        }
        return subsets_helper(nums, 0, 0, target);
    }
    int subsets_helper(const std::vector<int>& nums, size_t ind, int curr_max, int target) {
        if (ind >= nums.size()) {
            return 0;
        }
        int res = 0;
        res += subsets_helper(nums, ind + 1, curr_max, target);
        curr_max |= nums[ind];
        if (curr_max == target) {
            // Shift left because in the rest of the tree there are 2^n permutations & we need them all
            res += 1 << (nums.size() - 1 - ind);
            return res;
        }
        return res + subsets_helper(nums, ind + 1, curr_max, target);
    }
};
