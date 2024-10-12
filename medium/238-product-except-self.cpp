/**
 * @file: 238-product-except-self.cpp
 * @author: Perry Huang
 * @date: 3/26/2024
 * 238. Product of Array Except Self
 * Given an integer array nums, return an array answer such that answer[i] 
 * is equal to the product of all the elements of nums except nums[i].
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 */

#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
  std::vector<int> ans(nums);
  std::size_t cap = nums.size();
  for (std::size_t i = 1; i < cap; ++i) {
    nums[i] *= nums[i - 1];
    ans[cap - i - 1] *= ans[cap - i];
  }
  for (std::size_t i = 0; i < cap; ++i) {
    ans[i] = 1;
    if (i > 0) ans[i] *= nums[i - 1];
    if (i < cap - 1) ans[i] *= ans[i + 1];
  }
  return ans;
}

int main() {
  std::vector<int> naturals = {1, 2, 3, 4, 5};
  std::vector<int> products = productExceptSelf(naturals);
  for (int i : products) std::cout << i << " ";
  std::cout << "\n";
}
