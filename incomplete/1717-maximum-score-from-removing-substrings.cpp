/**
 * @file 1717-maximum-score-from-removing-substrings.cpp
 * @author Perry Huang
 * @date 2025-07-22
 * 1717. Maximum Score From Removing Substrings
 * You are given a string s and two integers x and y. You can perform two types of operations any number of times.
 * Remove substring "ab" and gain x points.
 * For example, when removing "ab" from "cabxbae" it becomes "cxbae".
 * Remove substring "ba" and gain y points.
 * For example, when removing "ba" from "cabxbae" it becomes "cabxe".
 * Return the maximum points you can gain after applying the above operations on s.
 */

#include <string>

class Solution {
public:
    int maximumGain(std::string s, int x, int y) {
        std::string mostPts = "ba";
        std::string leastPts = "ab";
        if (x > y) {
            mostPts = "ab";
            leastPts = "ba";
        }
    }
};
