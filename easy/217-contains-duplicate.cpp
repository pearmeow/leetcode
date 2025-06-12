/**
 * @file 217-contains-duplicate.cpp
 * @author Perry Huang
 * @date 2025-01-09
 * 217. Contains Duplicate
 * Given an integer array nums, return true if any value appears at least twice in the array, 
 * and return false if every element is distinct.
 */

#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> set;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (set.find(nums[i]) != set.end()) {
            return true;
        }
        set.insert(nums[i]);
    }
    return false;
}
