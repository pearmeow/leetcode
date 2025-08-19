/**
 * @file 2348-number-of-zero-filled-subarrays.cpp
 * @author Perry Huang
 * @date 2025-08-18
 * 2348. Number of Zero-Filled Subarrays
 * Given an integer array nums, return the number of subarrays filled with 0.
 * A subarray is a contiguous non-empty sequence of elements within an array.
 */

#include <vector>

class Solution {
public:
    long long zeroFilledSubarray(std::vector<int>& nums) {
        long long consec_zeros = 0;
        long long subarrs = 0;
        for (int i : nums) {
            if (i == 0) {
                ++consec_zeros;
            } else {
                subarrs += calc_subarrs(consec_zeros);
                consec_zeros = 0;
            }
        }
        subarrs += calc_subarrs(consec_zeros);
        return subarrs;
    }
    long long calc_subarrs(long long zeros) {
        long long mult = 1;
        long long subarrs = 0;
        while (zeros != 0) {
            subarrs += mult * zeros;
            --zeros;
        }
        return subarrs;
    }
};
