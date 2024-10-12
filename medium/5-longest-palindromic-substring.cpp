/**
 * @file: 5-longest-palindromic-substring.cpp
 * @author: Perry Huang
 * @date: 2/1/2024
 * 5. Longest Palindromic Substring
 * Given a string s, return the longest palindromic substring in s.
 */

#include <iostream>
#include <vector>

/*
iterate through substring 2 chars at a time
*/
std::string longestPalindrome(const std::string& s) {
  std::string res = "";
  int start = 0;
  int end = 0;
  int longest = 0;
  for (size_t i = 0; i < s.size() - 1; ++i) {
    if (s[i] == s[i + 1]) {
    } else {
      return "x";
    }
  }
  return res;
}

int main() { return 0; }
