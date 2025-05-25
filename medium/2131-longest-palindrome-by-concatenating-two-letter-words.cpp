/**
 * @file 2131-longest-palindrome-by-concatenating-two-letter-words.cpp
 * @author Perry Huang
 * @date 2025-05-24
 * 2131. Longest Palindrome by Concatenating Two Letter Words
 * You are given an array of strings words. Each element of words consists of two lowercase English letters.
 * Create the longest possible palindrome by selecting some elements from words and concatenating them in any order.
 * Each element can be selected at most once.
 * Return the length of the longest palindrome that you can create.
 * If it is impossible to create any palindrome, return 0.
 * A palindrome is a string that reads the same forward and backward.
 */

#include <string>
#include <vector>
#include <unordered_map>

int longestPalindrome(std::vector<std::string>& words) {
  int res = 0;
  int oddCouples = 0; // a "couple" is a word that is a palindrome
  std::string complement;
  std::unordered_map<std::string, int> wordCount;
  for (size_t i = 0; i < words.size(); ++i) {
    wordCount[words[i]] += 1;
    if (words[i][0] == words[i][1]) {
      if (wordCount[words[i]] % 2 == 0) { // even number of "couples"
        oddCouples -= 1;
        res += 4;
      } else { // odd number of "couples"
        oddCouples += 1;
      }
    } else {
      if (wordCount[{words[i][1], words[i][0]}] >= wordCount[words[i]]) { // check complement of word
          res += 4;
      }
    }
  }
  if (oddCouples >= 1) { // only count one of the odd couples toward the palindrome (in the middle)
    res += 2;
  }
  return res;
}
