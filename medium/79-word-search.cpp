/**
 * @file 79-word-search.cpp
 * @author Perry Huang
 * @date 2024-10-13
 * 79. Word Search
 * Given an m x n grid of characters board and a string word,
 * return true if word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. 
 * The same letter cell may not be used more than once.
 */

#include <vector>
#include <string>

bool helper(std::vector<std::vector<char>>& board, const std::string& word,
        int row, int col, int strInd, std::vector<std::vector<int>>& used) {
    if (strInd >= word.size()) return true; // done because we matched the entire string
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return false; // out of bounds
    if (used[row][col] == 1) return false;  // if we already used it
    if (board[row][col] == word[strInd]) {  // matching the character
        used[row][col] = 1;
    } else {
        return false;
    }
    if (helper(board, word, row + 1, col, strInd + 1, used) ||
            helper(board, word, row - 1, col, strInd + 1, used) ||
            helper(board, word, row, col + 1, strInd + 1, used) ||
            helper(board, word, row, col - 1, strInd + 1, used)) {
        return true;
    }
    used[row][col] = 0;
    return false;
}

bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
    std::vector<std::vector<int>> used(board.size(), std::vector<int>(board[0].size(), 0));
    for (std::size_t i = 0; i < used.size(); ++i) {
        for (std::size_t j = 0; j < used[i].size(); ++j) {
            if (helper(board, word, i, j, 0, used) == true) return true;
        }
    }
    return false;
}
