/**
 * @file 2099-find-subsequence-of-length-k-with-the-largest-sum.cpp
 * @author Perry Huang
 * @date 2025-06-27
 * 2099. Find Subsequence of Length K With the Largest Sum
 * You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that
 * has the largest sum. Return any such subsequence as an integer array of length k. A subsequence is an array that
 * can be derived from another array by deleting some or no elements without changing the order of the remaining
 * elements.
 */

#include <algorithm>
#include <queue>
#include <vector>

class Solution {
    std::vector<int> maxSubsequence(std::vector<int>& nums, int k) {
        auto comp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.first < b.first; };
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comp)> pq(comp);
        for (size_t i = 0; i < nums.size(); ++i) {
            pq.push(std::make_pair(nums[i], i));
        }
        std::vector<int> indices;
        for (int i = 0; i < k; ++i) {
            indices.push_back(pq.top().second);
            pq.pop();
        }
        std::sort(indices.begin(), indices.end());
        std::vector<int> res;
        for (int i : indices) {
            res.push_back(nums[i]);
        }
        return res;
    }
};
