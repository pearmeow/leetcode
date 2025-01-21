/**
 * @file 347-top-k-frequent-elems.cpp
 * @author Perry Huang
 * @date 2025-01-19
 * 347. Top K Frequent Elements
 * Given an integer array nums and an integer k, return the k most frequent elements.
 * You may return the answer in any order.
 */

#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>

class CompSecond {
public:
  bool operator() (const std::pair<int, int>& lhs, const std::pair<int, int>& rhs) const {
    return lhs.second < rhs.second;
  }
};

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
  std::unordered_map<int, int> frequencies;
  std::vector<std::pair<int, int>> pairs;
  std::vector<int> res;
  for (size_t i = 0; i < nums.size(); ++i) {
    if (frequencies.find(nums[i]) == frequencies.end()) {
      frequencies[nums[i]] = 1;
      pairs.push_back({nums[i], 0});
    } else {
      ++frequencies[nums[i]];
    }
  }
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CompSecond> pq;
  for (size_t i = 0; i < pairs.size(); ++i) {
    pairs[i].second = frequencies[pairs[i].first];
    pq.push(pairs[i]);
  }
  for (size_t i = 0; i < k; ++i) {
    res.push_back(pq.top().first);
    pq.pop();
  }

  return res;
}
