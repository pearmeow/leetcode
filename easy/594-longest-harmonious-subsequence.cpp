/**
 * @file 594-longest-harmonious-subsequence.cpp
 * @author Perry Huang
 * @date 2025-06-29
 * 594. Longest Harmonious Subsequence
 * We define a harmonious array as an array where the difference between its maximum value and its minimum value is
 * exactly 1. Given an integer array nums, return the length of its longest harmonious subsequence among all its
 * possible subsequences.
 */

#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
    int findLHS(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        int curr = nums[0];
        int currTotal = 1;
        int prevTotal = 0;
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == curr) {
                ++currTotal;
            } else if (nums[i] - 1 == curr) {
                if (prevTotal != 0) {
                    res = std::max(prevTotal + currTotal, res);
                }
                curr = nums[i];
                prevTotal = currTotal;
                currTotal = 1;
            } else {
                if (prevTotal != 0) {
                    res = std::max(prevTotal + currTotal, res);
                }
                curr = nums[i];
                prevTotal = 0;
                currTotal = 1;
            }
        }
        if (prevTotal != 0) {
            res = std::max(prevTotal + currTotal, res);
        }
        return res;
    }

    // Hashmap version
    int findLHSHashMap(std::vector<int>& nums) {
        std::unordered_map<int, int> freqs;
        for (int i : nums) {
            if (freqs.find(i) == freqs.end()) {
                freqs[i] = 1;
            } else {
                ++freqs[i];
            }
        }
        int theMax = 0;
        for (const std::pair<int, int>& curr : freqs) {
            int prev = 0;
            int next = 0;
            if (freqs.find(curr.first - 1) != freqs.end()) {
                prev = freqs.at(curr.first - 1);
            }
            if (freqs.find(curr.first + 1) != freqs.end()) {
                next = freqs.at(curr.first + 1);
            }
            if (prev != 0 || next != 0) {
                theMax = std::max(theMax, std::max(curr.second + next, curr.second + prev));
            }
        }
        return theMax;
    }
};
