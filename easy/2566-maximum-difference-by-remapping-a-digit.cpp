/*
 * @file 2566-maximum-difference-by-remapping-a-digit.cpp
 * @author Perry Huang
 * @date 2025-06-13
 * 2566. Maximum Difference by Remapping a Digit
 * You are given an integer num. You know that Bob will sneakily remap one of
 * the 10 possible digits (0 to 9) to another digit.
 * Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.
 * Notes:
 * When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
 * Bob can remap a digit to itself, in which case num does not change.
 * Bob can remap different digits for obtaining minimum and maximum values respectively.
 * The resulting number after remapping can contain leading zeroes.
 */

#include <vector>

class Solution {
    int minMaxDifference(int num) {
        std::vector<int> maxNum;
        while (num != 0) {
            maxNum.push_back(num % 10);
            num /= 10;
        }
        std::vector<int> minNum(maxNum);
        int maxRemap = -1;
        int minRemap = -1;
        for (size_t i = maxNum.size(); i > 0; --i) {
            if (maxRemap == -1 && maxNum[i - 1] != 9) {
                maxRemap = maxNum[i - 1];
            }
            if (minRemap == -1 && maxNum[i - 1] != 0) {
                minRemap = maxNum[i - 1];
            }
        }
        int theMax = 0;
        int theMin = 0;
        for (size_t i = maxNum.size(); i > 0; --i) {
            if (maxNum[i - 1] == maxRemap) {
                maxNum[i - 1] = 9;
            }
            if (minNum[i - 1] == minRemap) {
                minNum[i - 1] = 0;
            }
            theMax = theMax * 10 + maxNum[i - 1];
            theMin = theMin * 10 + minNum[i - 1];
        }
        return theMax - theMin;
    }
};
