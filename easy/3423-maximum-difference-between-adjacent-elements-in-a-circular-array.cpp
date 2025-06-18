/**
 * @file 3423-maximum-difference-between-adjacent-elements-in-a-circular-array.cpp
 * @author Perry Huang
 * @date 2025-06-11
 * 3423. Maximum Difference Between Adjacent Elements in a Circular Array
 * Given a circular array nums, find the maximum absolute difference between adjacent elements.
 * Note: In a circular array, the first and last elements are adjacent.
 */

#include <cmath>
#include <vector>

int maxAdjacentDistance(const std::vector<int>& nums) {
    int distance = std::abs(nums[0] - nums[nums.size() - 1]);
    for (size_t i = 0; i < nums.size() - 1; ++i) {
        distance = std::max(distance, std::abs(nums[i] - nums[i + 1]));
    }
    return distance;
}
