/**
 * @file 1394-find-lucky-integer-in-an-array.cpp
 * @author Perry Huang
 * @date 2025-07-04
 * 1394. Find Lucky Integer in an Array
 * Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
 * Return the largest lucky integer in the array. If there is no lucky integer return -1.
 */

#include <vector>
#include <map>

int findLucky(std::vector<int>& arr) {
    std::map<int, int> freqs;
    for (int i : arr) {
        if (freqs.find(i) == freqs.end()) {
            freqs[i] = 1;
        } else {
            ++freqs[i];
        }
    }
    int luckyMax = -1;
    for (const std::pair<int, int>& num : freqs) {
        if (num.first == num.second) {
            luckyMax = std::max(luckyMax, num.first);
        }
    }
    return luckyMax;
}
