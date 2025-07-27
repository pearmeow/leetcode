/**
 * @file 26-remove-dupes.cpp
 * @author Perry Huang
 * @date 2024-11-04
 * 26. Remove Duplicates from Sorted Array
 * Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique
 * element appears only once. The relative order of the elements should be kept the same. Then return the number of
 * unique elements in nums.
 */

#include <vector>

class Solution {
    int removeDuplicates(std::vector<int>& nums) {
        size_t insert = 0;
        int curr = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] != curr) {
                ++insert;
                nums[insert] = nums[i];
                curr = nums[i];
            }
        }
        return insert + 1;
    }
};
