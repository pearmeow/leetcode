/*
@file : 11.cpp
@author : Perry Huang
@date 2/25/2024

11. Container With Most Water
Description of problem:
You are given an integer array height of length n. 
There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.
*/

#include <vector>
#include <iostream>
#include <cmath>

int maxArea(std::vector<int>& height) {
  int res = 0;
  for (int i = 0; i < height.size(); ++i) {
    for (int j = i; j < height.size(); ++j) {
      res = std::max(res, (j - i) * std::min(height[i], height[j]));
    }
  }
  return res;
}