/**
 * @file 75-sort-colors.cpp
 * @author Perry Huang
 * @date 2025-05-16
 * 75. Sort Colors
 * Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color 
 * are adjacent, with the colors in the order red, white, and blue.
 * We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
 * You must solve this problem without using the library's sort function.
 */

#include <vector>
#include <utility>

void sortColors(std::vector<int>& nums) {
    if (nums.size() < 2) return;
    size_t back = nums.size() - 1;
    size_t front = 0;
    while (nums[back] == 2 && back != 0) --back;
    while (nums[front] == 0 && front < nums.size() - 1) ++front;
    if (back == 0 || front == nums.size() - 1) return;
    size_t curr = front;
    while (curr <= back) {
        if (nums[curr] == 2) {
            std::swap(nums[curr], nums[back]);
            --back;
            if (nums[curr] == 0) {
                std::swap(nums[curr], nums[front]);
                ++front;
            }
            while (nums[back] == 2 && back != 0) --back;
        } else if (nums[curr] == 0) {
            std::swap(nums[curr], nums[front]);
            ++front;
        }
        ++curr;
    }
}
