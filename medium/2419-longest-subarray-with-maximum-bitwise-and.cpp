/**
 * @file 2419-longest-subarray-with-maximum-bitwise-and.cpp
 * @author Perry Huang
 * @date 2025-07-29
 * 2419. Longest Subarray With Maximum Bitwise AND
 * You are given an integer array nums of size n.
 * Consider a non-empty subarray from nums that has the maximum possible bitwise AND.
 * In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with
 * a bitwise AND equal to k should be considered. Return the length of the longest such subarray. The bitwise AND
 * of an array is the bitwise AND of all the numbers in it. A subarray is a contiguous sequence of elements within
 * an array.
 */

#include <vector>

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int max_sub = 0;
        int curr_sub = 0;
        int max_num = 0;
        for (int i : nums) {
            if (i > max_num) {
                max_sub = 1;
                curr_sub = 1;
                max_num = i;
            } else if (i == max_num) {
                ++curr_sub;
                max_sub = std::max(max_sub, curr_sub);
            } else {
                curr_sub = 0;
            }
        }
        return max_sub;
    }
};
