/**
 * @file 2200-find-all-k-distant-indices-in-an-array.cpp
 * @author Perry Huang
 * @date 2025-06-24
 * 2200. Find All K-Distant Indices in an Array
 * You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums
 * for which there exists at least one index j such that |i - j| <= k and nums[j] == key. Return a list of all
 * k-distant indices sorted in increasing order.
 */

#include <vector>

class Solution {
    std::vector<int> findKDistantIndices(std::vector<int>& nums, int key, int k) {
        std::vector<int> res;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == key) {
                size_t start = 0;
                if (k < i) {
                    start = i - k;
                }
                if (!res.empty()) {
                    start = std::max((size_t)res[res.size() - 1], start);
                }
                size_t end = std::min(i + k + 1, nums.size());
                for (size_t j = start; j < end; ++j) {
                    if (res.empty()) {
                        res.push_back(j);
                    } else if (res[res.size() - 1] < j) {
                        res.push_back(j);
                    }
                }
            }
        }
        return res;
    }
};
