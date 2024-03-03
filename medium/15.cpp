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
  std::unordered_map<int, int> numIndex;
  std::unordered_map<int, std::vector<int>> seen;
  

  return triplets;
}

int main() {
  std::unordered_map<int, std::vector<int>> numIndex;
  numIndex[0] = {1, 2};
  std::cout << numIndex[0][0];
}