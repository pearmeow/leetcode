/**
 * @file 516-longest-palindromic-subsequence.cpp
 * @author Perry Huang
 * @date 2025-05-27
 * 516. Longest Palindromic Subsequence
 * Given a string s, find the longest palindromic subsequence's length in s.
 * A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without
 * changing the order of the remaining elements.
 */

#include <string>
#include <vector>

class Solution {
public:
    void updTable(const std::string& s, size_t row, size_t col, std::vector<std::vector<int>>& dp) {
        if (col == 0 || col > dp.size() - 1 || row >= dp.size() - 1) return;
        if (s[row] == s[col]) {
            dp[row][col] = 2 + dp[row + 1][col - 1];
        } else {
            dp[row][col] = std::max(dp[row + 1][col], dp[row][col - 1]);
        }
    }

    int longestPalindromeSubseq(const std::string& s) {
        // dp[i,j] is the longest palindrome from i to j
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size()));
        for (size_t i = 0; i < dp.size(); ++i) {
            // base case i == j and size is 1
            dp[i][i] = 1;
        }
        // traverses the table diagonally
        for (size_t offset = 1; offset < dp.size(); ++offset) {
            for (size_t row = 0, col = offset; col < dp.size(); ++row, ++col) {
                updTable(s, row, col, dp);
            }
        }
        return dp[0][s.size() - 1];
    }
};
