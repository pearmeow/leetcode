/**
 * @file 2311-longest-binary-subsequence-less-than-or-equal-to-k.cpp
 * @author Perry Huang
 * @date 2025-06-25
 * 2311. Longest Binary Subsequence Less Than or Equal to K
 * You are given a binary string s and a positive integer k.
 * Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.
 * Note:
 * The subsequence can contain leading zeroes.
 * The empty string is considered to be equal to 0.
 * A subsequence is a string that can be derived from another string by deleting some or no characters without
 * changing the order of the remaining characters.
 */

#include <string>

class Solution {
   public:
    int longestSubsequence(const std::string& s, int k) {
        long long res = 0;
        long long currTotal = 0;
        long long currAdd = 1;
        for (size_t dec = 1; dec <= s.size(); ++dec) {
            if (currTotal + currAdd <= k && s[s.size() - dec] == '1') {
                currTotal += currAdd;
                currAdd *= 2;
                ++res;
            } else if (s[s.size() - dec] == '0') {
                if (currAdd + currTotal <= k) {
                    currAdd *= 2;
                }
                ++res;
            }
        }
        return res;
    }
};
