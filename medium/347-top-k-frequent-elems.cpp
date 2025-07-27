/**
 * @file 347-top-k-frequent-elems.cpp
 * @author Perry Huang
 * @date 2025-01-19
 * 347. Top K Frequent Elements
 * Given an integer array nums and an integer k, return the k most frequent elements.
 * You may return the answer in any order.
 */

#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    class pairComparator {
       public:
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second;
        }
    };

    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> posInVector;
        std::vector<std::pair<int, int>> numCount;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (posInVector.find(nums[i]) == posInVector.end()) {
                posInVector[nums[i]] = numCount.size();
                numCount.emplace_back(nums[i], 1);
            } else {
                ++numCount[posInVector[nums[i]]].second;
            }
        }
        pairComparator comp;
        sort(numCount.begin(), numCount.end(), comp);
        std::vector<int> kFreq(k);
        for (size_t i = 0; i < k; ++i) {
            kFreq[i] = numCount[i].first;
        }
        return kFreq;
    }
};
