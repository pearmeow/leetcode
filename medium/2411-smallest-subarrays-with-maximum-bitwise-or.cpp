/**
 * @file 2411-smallest-subarrays-with-maximum-bitwise-or.cpp
 * @author Perry Huang
 * @date 2025-07-28
 * 2411. Smallest Subarrays With Maximum Bitwise OR
 * You are given a 0-indexed array nums of length n, consisting of non-negative integers. For each index i from 0
 * to n - 1, you must determine the size of the minimum sized non-empty subarray of nums starting at i (inclusive)
 * that has the maximum possible bitwise OR. In other words, let Bij be the bitwise OR of the subarray nums[i...j].
 * You need to find the smallest subarray starting at i, such that bitwise OR of this subarray is equal to max(Bik)
 * where i <= k <= n - 1. The bitwise OR of an array is the bitwise OR of all the numbers in it. Return an integer
 * array answer of size n where answer[i] is the length of the minimum sized subarray starting at i with maximum
 * bitwise OR. A subarray is a contiguous non-empty sequence of elements within an array.
 */

#include <vector>

class Solution {
public:
    std::vector<int> smallestSubarrays(std::vector<int>& nums) {
        std::vector<int> nearest_bit_inds(32, 0);
        std::vector<int> res(nums.size(), 1);
        for (size_t decr = 1; decr <= nums.size(); ++decr) {
            int index = nums.size() - decr;
            int curr_num = nums[index];
            int bit_ind = 0;
            while (curr_num != 0 || bit_ind < nearest_bit_inds.size()) {
                int least_sig_bit = curr_num & 1;
                if (least_sig_bit == 1) {
                    nearest_bit_inds[bit_ind] = index;
                }
                int distance = nearest_bit_inds[bit_ind] - index + 1;
                res[index] = std::max(distance, res[index]);
                curr_num >>= 1;
                ++bit_ind;
            }
        }
        return res;
    }
};
