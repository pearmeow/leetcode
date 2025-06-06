/**
 * @file 3355-zero-array-transformation-i.cpp
 * @author Perry Huang
 * @date 2025-05-19
 * 3355. Zero Array Transformation I
 * You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].
 * For each queries[i]:
 * Select a subset of indices within the range [li, ri] in nums.
 * Decrement the values at the selected indices by 1.
 * A Zero Array is an array where all elements are equal to 0.
 * Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially,
 * otherwise return false.
 */

#include <vector>

bool isZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    std::vector<int> diff_vec(nums.size() + 1, 0); // +1 for difference array
    for (size_t i = 0; i < queries.size(); ++i) {  // how does this loop work?
        ++diff_vec[queries[i][0]]; // the start of the range is incremented
        diff_vec[queries[i][1] + 1] -= 1; // the index at the end of the range +1 is decremented
    } // arriving at an index after this loop will give you the number of ranges included
      // and when they end they are subtracted away
    int diff = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        diff += diff_vec[i];
        if (nums[i] > diff) return false;
    }
    return true;
}
