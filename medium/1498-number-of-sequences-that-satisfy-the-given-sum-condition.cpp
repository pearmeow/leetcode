/**
 * @file 1498-number-of-sequences-that-satisfy-the-given-sum-condition.cpp
 * @author Perry Huang
 * @date 2025-06-28
 * 1498. Number of Subsequences That Satisfy the Given Sum Condition
 * You are given an array of integers nums and an integer target.
 * Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it
 * is less or equal to target. Since the answer may be too large, return it modulo 10^9 + 7.
 */

#include <algorithm>
#include <vector>

class Solution {
   public:
    long long myPow(long long base, long long exp) {
        if (exp == 0) {
            return 1;
        }
        if (exp == 1) {
            return base;
        }
        long long squareThis = myPow(base, exp / 2);
        if (exp % 2 == 0) {  // even, so don't multiply by base
            base = 1;
        }
        return (base * squareThis * squareThis) % 1000000007;
    }

    int numSubseq(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        long long res = 0;
        size_t start = 0;
        size_t end = nums.size() - 1;
        while (start < end) {
            if (nums[start] + nums[end] > target) {
                --end;
            } else {
                long long numsBtwn = start - end - 1;
                res += myPow(2, numsBtwn + 1) - 1;
                ++start;
            }
        }
        long long singleSubs = (std::lower_bound(nums.begin(), nums.end(), target / 2 + 1) - nums.begin());
        res += singleSubs;
        return res % 1000000007;
    }
};
