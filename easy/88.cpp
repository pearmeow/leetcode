/*
88. Merge Sorted Array
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should
be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
*/

#include <vector>
#include <iostream>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
  std::vector<int> n1cpy;
  //copy the important indicies from nums2 into a copy so we can modify nums2 later
  for (std::size_t i = 0; i < m; ++i) n1cpy.push_back(nums1[i]);
  std::size_t pos1 = 0, pos2 = 0;
  int x = 0;
  for (std::size_t i = 0; i < nums1.size(); ++i) {
    if (pos1 < m && pos2 < n) {
      if (n1cpy[pos1] <= nums2[pos2]) {
        x = n1cpy[pos1];
        ++pos1;
      }
      else {
        x = nums2[pos2];
        ++pos2;
      }
    }
    else if (pos2 >= n) {
      x = n1cpy[pos1];
      ++pos1;
    }
    else {
      x = nums2[pos2];
      ++pos2;
    }
    nums1[i] = x;
  }
}

int main(int argc, char* argv[]) {
  std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  std::vector<int> nums2 = {2, 5, 6};
  merge(nums1, 3, nums2, 3);
  for (int i : nums1) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}