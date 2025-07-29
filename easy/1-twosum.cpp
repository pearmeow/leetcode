/**
 * @file 1-twosum.cpp
 * @author Perry Huang
 * @date 2024-10-12
 * 1. Two Sum
 * Given an array of integers nums and an integer target, return indices of the two
 * numbers such that they add up to target. You may assume that each input would
 * have exactly one solution, and you may not use the same element twice. You can
 * public:
 * return the answer in any order.
 */

#include <unordered_map>
#include <vector>

class Solution {
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> solution;
        std::unordered_map<int, int> indices;
        for (size_t i = 0; i < nums.size(); ++i) {
            int curr = nums[i];
            int complement = target - nums[i];
            if (indices.find(complement) != indices.end()) {
                solution.push_back(indices[complement]);
                solution.push_back(i);
                return solution;
            }
            indices[curr] = i;
        }
        return solution;
    }
};
