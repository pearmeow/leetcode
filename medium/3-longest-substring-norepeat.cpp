/**
 * @file 3-longest-substring-norepeat.cpp
 * @author Perry Huang
 * @date 2024-10-12
 * 3. Longest Substring Without Repeating Characters
 * Given a string s, find the length of the longest
 * substring without repeating characters.
 */

#include <iostream>  //for testing
#include <string>
#include <unordered_map>

int lengthOfLongestSubstring(const std::string& s) {
  std::unordered_map<char, int> charPositions;
  int longestSub = 0;
  int offset = 0;
  for (int pos = 0; pos < s.size();
       ++pos) {                           // iterate through each character in s
    int charPos = charPositions[s[pos]];  // see if the current character exists
    if (charPos != 0) {  // if character exists in the substring
      offset = std::max(
          offset,
          charPos);  // offset to right in front of that char if it's greater
    }
    charPositions[s[pos]] = pos + 1;  // set the position to the current one
    longestSub = std::max(longestSub, (pos + 1 - offset));  // update length
  }
  return longestSub;
}

int main() {
  std::string sample = "bacdefghijab";  // expecting 10
  std::cout << lengthOfLongestSubstring(sample);
  return 0;
}
