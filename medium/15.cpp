/*
@file: 15.cpp
@author: Perry Huang
@date: 2/26/2024

15. 3Sum
Given an integer array nums, return all the triplets
[nums[i], nums[j], nums[k]] such that
i != j, i != k, and j != k
nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
  std::vector<std::vector<int>> triplets;
  std::vector<int> seen1(nums.size() - 2, 0);
  std::vector<std::vector<int>> seen2(nums.size() - 2, std::vector<int>(nums.size() - 1, 0));
  std::unordered_map<int, int> valTable;
  for (size_t i = 0; i < nums.size(); ++i) valTable[nums[i]] = i;
  for ()

  return triplets;
}

int main() {
  return 0;
}