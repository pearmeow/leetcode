/**
 * @file: 5-longest-palindromic-substring.cpp
 * @author: Perry Huang
 * @date: 2/1/2024
 * 5. Longest Palindromic Substring
 * Given a string s, return the longest palindromic substring in s.
 */

#include <string>
#include <vector>
#include <iostream>

void updTable(const std::string& s, size_t row, size_t col, std::vector<std::vector<std::pair<size_t, size_t>>>& dp) {
    if (col == 0 || col > dp.size() - 1 || row >= dp.size() - 1) return;
    size_t start = dp[row + 1][col - 1].first;
    size_t end = dp[row + 1][col - 1].second;
    if (s[row] == s[col]) {
        if (row + 1 > col - 1 || (start == row + 1 && end == col - 1)) {
            dp[row][col].first = row;
            dp[row][col].second = col;
        }
    }
}

std::string longestPalindrome(const std::string& s) {
    // dp[i,j] is the longest palindrome from i to j
    std::vector<std::vector<std::pair<size_t, size_t>>> dp(s.size(), std::vector<std::pair<size_t, size_t>>(s.size(),
                std::pair<int,int>(s.size(), s.size()))); // first is start index, second is end index
    for (size_t i = 0; i < dp.size(); ++i) {
        // base case i == j so size is 1
        dp[i][i].first = i;
        dp[i][i].second = i;
    }
    // traverse table diagonally
    for (size_t offset = 1; offset < dp.size(); ++offset) {
        for (size_t row = 0, col = offset; col < dp.size(); ++row, ++col) {
            updTable(s, row, col, dp);
        }
    }
    std::size_t start = 0;
    std::size_t end = 0;
    std::size_t longest = 0;
    for (size_t i = 0; i < dp.size(); ++i) {
        for (size_t j = 0; j < dp.size(); ++j) {
            if (dp[i][j].first != dp.size() && (longest < dp[i][j].second - dp[i][j].first + 1)) {
                longest = dp[i][j].second - dp[i][j].first + 1;
                start = dp[i][j].first;
                end = dp[i][j].second;
            }
        }
    }
    return s.substr(start, end - start + 1);
}
