/**
 * @file 647-palindromic-substrings.cpp
 * @author Perry Huang
 * @date 2025-07-23
 * 647. Palindromic Substrings
 * Given a string s, return the number of palindromic substrings in it.
 * A string is a palindrome when it reads the same backward as forward.
 * A substring is a contiguous sequence of characters within the string.
 */

#include <string>
#include <vector>

int countSubstrings(const std::string& s) {
    std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 0));

}

