/**
 * @file 242-valid-anagram.cpp
 * @author Perry Huang
 * @date 2025-01-11
 * 242. Valid Anagram
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 */

#include <string>
#include <unordered_map>
#include <iostream>

bool isAnagram(const std::string& s, const std::string& t) {
  if (s.size() != t.size()) return false;
  std::unordered_map<char, int> chars;

  // first put everything from s in the unordered map
  // each char will correspond to how many times it's appeared

  for (size_t i = 0; i < s.size(); ++i) {
    if (chars.find(s[i]) == chars.end()) {
      chars[s[i]] = 1;
    } else {
      chars[s[i]] += 1;
    }
  }

  // now subtract every character from t
  // if it doesn't exist or goes below 0, then t is not an anagram

  for (size_t i = 0; i < t.size(); ++i) {
    if (chars.find(t[i]) == chars.end()) return false;
    chars[t[i]] -= 1;
    if (chars[t[i]] < 0) return false;
  }

  return true;
}

int main() {
  std::string test1 = "burh";
  std::string test2 = "urhb";
  if (isAnagram(test1, test2)) {
    std::cout << test1 << " and " << test2 << " are anagrams";
  } else {
    std::cout << test1 << " and " << test2 << " are not anagrams";
  }
  std::cout << "\n";
  test1 = "   ";
  test2 = "   ";
  if (isAnagram(test1, test2)) {
    std::cout << test1 << " and " << test2 << " are anagrams";
  } else {
    std::cout << test1 << " and " << test2 << " are not anagrams";
  }
  std::cout << "\n";
  test1 = "@4$";
  test2 = "$@4";
  if (isAnagram(test1, test2)) {
    std::cout << test1 << " and " << test2 << " are anagrams";
  } else {
    std::cout << test1 << " and " << test2 << " are not anagrams";
  }
  std::cout << "\n";
  test1 = "@4$ ";
  test2 = "$@4";
  if (isAnagram(test1, test2)) {
    std::cout << test1 << " and " << test2 << " are anagrams";
  } else {
    std::cout << test1 << " and " << test2 << " are not anagrams";
  }
}
