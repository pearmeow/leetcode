/**
 * @file 2210-count-hills-and-valleys-in-an-array.cpp
 * @author Perry Huang
 * @date 2025-07-26
 * 2210. Count Hills and Valleys in an Array
 * You are given a 0-indexed integer array nums. An index i is part of a hill in nums if the closest non-equal
 * neighbors of i are smaller than nums[i]. Similarly, an index i is part of a valley in nums if the closest
 * non-equal neighbors of i are larger than nums[i]. Adjacent indices i and j are part of the same hill or valley
 * if nums[i] == nums[j]. Note that for an index to be part of a hill or valley, it must have a non-equal neighbor
 * on both the left and right of the index. Return the number of hills and valleys in nums.
 */

#include <vector>

int countHillValley(const std::vector<int>& nums) {
    std::vector<int> curr_hill_valley;
    int res = 0;
    for (int i : nums) {
        size_t currSize = curr_hill_valley.size();
        if (currSize == 0) {
            curr_hill_valley.push_back(i);
        } else if (currSize < 3) {
            if (curr_hill_valley[currSize - 1] != i) {
                curr_hill_valley.push_back(i);
            }
        } else {
            if (curr_hill_valley[currSize - 1] != i) {
                int left = curr_hill_valley[0];
                int mid = curr_hill_valley[1];
                int right = curr_hill_valley[2];
                if (mid > left && mid > right) {
                    ++res;
                } else if (mid < left && mid < right) {
                    ++res;
                }
                curr_hill_valley[0] = mid;
                curr_hill_valley[1] = right;
                curr_hill_valley[2] = i;
            }
        }
    }
    if (curr_hill_valley.size() < 3) {
        return res;
    }
    int left = curr_hill_valley[0];
    int mid = curr_hill_valley[1];
    int right = curr_hill_valley[2];
    if (mid > left && mid > right) {
        ++res;
    } else if (mid < left && mid < right) {
        ++res;
    }
    return res;
}
