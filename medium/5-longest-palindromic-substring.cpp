/**
 * @file: 5-longest-palindromic-substring.cpp
 * @author: Perry Huang
 * @date: 2/1/2024
 * 5. Longest Palindromic Substring
 * Given a string s, return the longest palindromic substring in s.
 */

#include <string>
#include <vector>

void updTable(const std::string& s, size_t row, size_t col, std::vector<std::vector<std::string>>& dp) {
  if (col == 0 || col > dp.size() - 1 || row >= dp.size() - 1) return;
  size_t nextRow = dp[row + 1][col].size();
  size_t prevCol = dp[row][col - 1].size();
  size_t diagonal = dp[row + 1][col - 1].size();
  if (s[row] == s[col]) {
    if ((row + 1 > col - 1 || diagonal == col - row - 1) && diagonal + 2 > nextRow && diagonal + 2 > prevCol) {
      dp[row][col] = s[row] + dp[row + 1][col - 1] + s[col];
    }
  }
  if (nextRow > prevCol) {
    dp[row][col] = dp[row + 1][col];
  } else {
    dp[row][col] = dp[row][col - 1];
  }
}

std::string longestPalindrome(const std::string& s) {
  // dp[i,j] is the longest palindrome from i to j
  std::vector<std::vector<std::string>> dp(s.size(), std::vector<std::string>(s.size(), ""));
  for (size_t i = 0; i < dp.size(); ++i) {
    // base case i == j and size is 1
    dp[i][i] = s[i];
  }
  // traverses the table diagonally
  for (size_t offset = 1; offset < dp.size(); ++offset) {
    for (size_t row = 0, col = offset; col < dp.size(); ++row, ++col) {
      updTable(s, row, col, dp);
    }
  }
  return dp[0][s.size() - 1];
}
