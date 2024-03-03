/*
@file: 70.cpp
@author: Perry Huang
@date: 3/2/2024

70. Climbing Stairs
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <vector>
#include <iostream>

int climbStairs(int n) {
  std::vector<int> ways = {1, 1};
  for (size_t i = 2; i < n + 1; ++i) {
    ways.push_back(ways[i - 1] + ways[i - 2]);
  }
  return ways[n];
}

int main() {
  std::cout << climbStairs(10) << std::endl;
}