/**
 * @file 898-bitwise-ors-of-subarrays.cpp
 * @author Perry Huang
 * @date 2025-07-30
 * 898. Bitwise ORs of Subarrays
 * Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
 * The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of
 * one integer is that integer. A subarray is a contiguous non-empty sequence of elements within an array.
 */

#include <unordered_set>
#include <vector>

class Solution {
public:
    int subarrayBitwiseORs(std::vector<int>& arr) {
        std::unordered_set<int> uniq_subarrs;
        for (size_t decr = 1; decr <= arr.size(); ++decr) {
            int curr = arr[arr.size() - decr];
            for (size_t i = arr.size() - decr; i < arr.size(); ++i) {
                curr = curr | arr[i];
                uniq_subarrs.insert(curr);
            }
        }
        return uniq_subarrs.size();
    }
};
