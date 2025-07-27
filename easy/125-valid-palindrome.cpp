/**
 * @file 125-valid-palindrome.cpp
 * @author Perry Huang
 * @date 2025-07-23
 * 125. Valid Palindrome
 * A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all
 * non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and
 * numbers. Given a string s, return true if it is a palindrome, or false otherwise.
 */

#include <string>

class Solution {
    bool isPalindrome(const std::string& s) {
        size_t left = 0;
        size_t right = s.size() - 1;
        while (left < right) {
            while (!std::isalnum(s[left]) && left < s.size()) {
                ++left;
            }
            while (!std::isalnum(s[right]) && right > 0) {
                --right;
            }
            if (left >= right) {
                break;
            }
            if (std::tolower(s[left]) != std::tolower(s[right])) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
