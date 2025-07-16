/**
 * @file 3201-find-the-maximum-length-of-valid-subsequence-i.cpp
 * @author Perry Huang
 * @date 2025-07-15
 * 3201. Find the Maximum Length of Valid Subsequence I
 * You are given an integer array nums.
 * A subsequence sub of nums with length x is called valid if it satisfies:
 * (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
 * Return the length of the longest valid subsequence of nums.
 * A subsequence is an array that can be derived from another array by deleting some or no elements without changing the
 * order of the remaining elements.
 */

#include <vector>

int maximumLength(std::vector<int>& nums) {
    int evens = 0;
    int odds = 0;
    int alternating = 0;
    bool nextIsEven = nums[0] % 2 == 0;
    for (int i : nums) {
        evens += (i + 1) % 2; // if it's even, adds one
        odds += i % 2;        // if it's odd, adds one
        if (nextIsEven == (i % 2 == 0)) {
            ++alternating;
            nextIsEven = !nextIsEven;
        }
    }
    return std::max(evens, std::max(odds, alternating));
}
