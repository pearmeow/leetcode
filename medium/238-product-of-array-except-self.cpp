/**
 * @file 238-product-of-array-except-self.cpp
 * @author Perry Huang
 * @date 2025-06-12
 * 238. Product of Array Except Self
 * Given an integer array nums, return an array answer such that answer[i]
 * is equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 */

#include <vector>

class Solution {
   public:
    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        std::vector<int> res(nums.size(), 1);
        int prev = 1;
        int prevReverse = 1;
        for (std::size_t i = 1; i < nums.size(); ++i) {
            prev *= nums[i - 1];
            res[i] *= prev;
            prevReverse *= nums[nums.size() - i];
            res[nums.size() - i - 1] *= prevReverse;
        }
        return res;
    }
};
