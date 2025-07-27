/**
 * @file 2966-divide-arrays-into-arrays-with-max-difference.cpp
 * @author Perry Huang
 * @date 2025-06-18
 * 2966. Divide Array Into Arrays With Max Difference
 * You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.
 * Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:
 * The difference between any two elements in one array is less than or equal to k.
 * Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.
 */

#include <algorithm>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
        std::vector<bool> taken(nums.size(), false);
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i + 2 < nums.size(); i += 3) {
            if (nums[i + 2] - nums[i] > k) {
                return {};
            } else {
                res.push_back({nums[i], nums[i + 1], nums[i + 2]});
            }
        }
        return res;
    }
};
