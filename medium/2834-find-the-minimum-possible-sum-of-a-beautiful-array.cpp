/**
 * @file 2834-find-the-minimum-possible-sum-of-a-beautiful-array.cpp
 * @author Perry Huang
 * @date 2025-06-15
 * 2834. Find the Minimum Possible Sum of a Beautiful Array
 * You are given positive integers n and target.
 * An array nums is beautiful if it meets the following conditions:
 * nums.length == n.
 * nums consists of pairwise distinct positive integers.
 * There doesn't exist two distinct indices, i and j, in the range [0, n - 1], such that nums[i] + nums[j] == target.
 * Return the minimum possible sum that a beautiful array could have modulo 10^9 + 7.
 */

#include <cmath>

int minimumPossibleSum(long long n, long long target) {
    long long minSum = 0;
    long long bound = target / 2;
    if (n <= bound) {
        minSum = (1 + n) * n / 2;
    } else if (n > bound) {
        if (bound > 0) {
            minSum = (1 + bound) * bound / 2;
            n -= bound;
        }
        minSum += (target + target + n - 1) * n / 2;
    }
    return minSum % ((long long)pow(10, 9) + 7);
}
