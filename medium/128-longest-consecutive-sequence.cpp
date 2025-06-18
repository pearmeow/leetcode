/**
 * @file 128-longest-consecutive-sequence.cpp
 * @author Perry Huang
 * @date 2025-06-14
 * 128. Longest Consecutive Sequence
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time.
 */

#include <unordered_map>
#include <vector>

// Hashmap solution
int longestConsecutive(std::vector<int>& nums) {
    int longest = 0;
    std::unordered_map<int, bool> numSet;
    for (int num : nums) {
        numSet[num] = false;
    }
    int curr = 0;
    for (int num : nums) {
        curr = 0;
        if (numSet.find(num - 1) == numSet.end()) {
            while (numSet.find(num) != numSet.end() && numSet[num] == false) {
                numSet[num] = true;
                ++curr;
                ++num;
            }
        }
        longest = std::max(longest, curr);
    }
    return longest;
}
