/**
 * @file 3362-zero-array-transformation-iii.cpp
 * @author Perry Huang
 * @date 2025-05-21
 * 3362. Zero Array Transformation III
 * You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].
 * Each queries[i] represents the following action on nums
 * Decrement the value at each index in the range [li, ri] in nums by at most 1
 * The amount by which the value is decremented can be chosen independently for each index
 * A Zero Array is an array with all its elements equal to 0
 * Return the maximum number of elements that can be removed from queries, such that nums can still be converted to
 * a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.
 */

#include <algorithm>
#include <queue>
#include <vector>

class Solution {
public:
    int maxRemoval(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        std::sort(queries.begin(), queries.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });                           // sorts by first index
        std::priority_queue<int> pq;  // stores queries by greatest right bound
        std::vector<int> diff_arr(nums.size() + 1, 0);
        int diff_sum = 0;
        for (size_t i = 0, j = 0; i < nums.size();
             ++i) {                   // i represents current nums index where queries are needed
            diff_sum += diff_arr[i];  // accounts for negatives set by previous right bounds
            while (j < queries.size() && queries[j][0] == i) {  // while left bound is equal to current nums index
                pq.push(queries[j][1]);                         // sorted queries means we'll never "miss" a query
                ++j;
            }
            while (!pq.empty() && diff_sum < nums[i] &&
                   pq.top() >= i) {      // pq top must be >= to i to cover it in the range
                int r_bound = pq.top();  // the left bound will never be "further" than i since we only account for
                                         // queries with
                pq.pop();                // left bounds less than or equal to i in the previous while loop
                ++diff_arr[i];           // unnecessary operation but makes diff_arr correct
                ++diff_sum;
                --diff_arr[r_bound + 1];
            }
            if (diff_sum < nums[i]) return -1;  // not enough queries
        }
        return pq.size();
    }
};
