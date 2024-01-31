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

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    std::vector<int> nums3;
    for (std::size_t ind = 0; ind < m; ++ind) {
        nums3.push_back(nums1[ind]);            //make vector with just the nums1 elements
    }
    int n2pos = 0;
    int n3pos = 0;
    for (std::size_t changes = 0; changes < m + n; ++changes) {
        if (n2pos < n && n3pos < m) {           //indicies not out of bound
            if (nums2[n2pos] <= nums3[n3pos]) { //check which one is smaller to insert
                nums1[changes] = nums2[n2pos];
                ++n2pos;
            }
            else {
                nums1[changes] = nums3[n3pos];
                ++n3pos;
            }
        }
        else {                                  //when one reaches the end, insert all the remains in the other one
            if (n2pos < n) {
                nums1[changes] = nums2[n2pos];
                ++n2pos;
            }
            else {
                nums1[changes] = nums3[n3pos];
                ++n3pos;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    return 0;
}