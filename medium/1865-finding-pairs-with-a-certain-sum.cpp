/**
 * @file 1865-finding-pairs-with-a-certain-sum.cpp
 * @author Perry Huang
 * @date 2025-07-27
 * 1865. Finding Pairs With a Certain Sum
 * You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports
 * queries of two types: Add a positive integer to an element of a given index in the array nums2. Count the number
 * of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j <
 * nums2.length). Implement the FindSumPairs class: FindSumPairs(int[] nums1, int[] nums2) Initializes the
 * FindSumPairs object with two integer arrays nums1 and nums2. void add(int index, int val) Adds val to
 * nums2[index], i.e., apply nums2[index] += val. int count(int tot) Returns the number of pairs (i, j) such that
 * nums1[i] + nums2[j] == tot.* @date 2025-07-06
 */

#include <unordered_map>
#include <vector>

class FindSumPairs {
public:
    FindSumPairs(std::vector<int>& nums1, std::vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int i : nums1) {
            if (freqs1.find(i) == freqs1.end()) {
                freqs1[i] = 1;
            } else {
                ++freqs1[i];
            }
        }
        for (int i : nums2) {
            if (freqs2.find(i) == freqs2.end()) {
                freqs2[i] = 1;
            } else {
                ++freqs2[i];
            }
        }
    }

    void add(int index, int val) {
        --freqs2[nums2[index]];
        nums2[index] += val;
        ++freqs2[nums2[index]];
    }

    int count(int tot) {
        int res = 0;
        for (const std::pair<int, int>& p : freqs1) {
            if (freqs2.find(tot - p.first) != freqs2.end()) {
                res += p.second * freqs2[tot - p.first];
            }
        }
        return res;
    }

private:
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::unordered_map<int, int> freqs1;
    std::unordered_map<int, int> freqs2;
};
