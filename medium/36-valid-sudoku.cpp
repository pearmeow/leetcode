/**
 * @file 36-valid-sudoku.cpp
 * @author Perry Huang
 * @date 2025-06-14
 * 36. Valid Sudoku
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * Note:
 * A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 */

#include <vector>

class Solution {
   public:
    void reset(std::vector<bool>& hasNum) {
        for (size_t i = 0; i < hasNum.size(); ++i) {
            hasNum[i] = false;
        }
    }

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<bool> hasNum(9, false);
        for (size_t row = 0; row < board.size(); ++row) {
            for (size_t col = 0; col < board[row].size(); ++col) {
                if (board[row][col] == '.') {
                    continue;
                }
                if (hasNum[board[row][col] - '1'] == true) {
                    return false;
                }
                hasNum[board[row][col] - '1'] = true;
            }
            reset(hasNum);
        }
        for (size_t col = 0; col < board.size(); ++col) {
            for (size_t row = 0; row < board.size(); ++row) {
                if (board[row][col] == '.') {
                    continue;
                }
                if (hasNum[board[row][col] - '1'] == true) {
                    return false;
                }
                hasNum[board[row][col] - '1'] = true;
            }
            reset(hasNum);
        }
        for (int offset = 0; offset < board.size(); offset += 3) {
            for (size_t row = 0; row < board.size(); ++row) {
                for (size_t col = offset; col < offset + 3; ++col) {
                    if (board[row][col] == '.') {
                        continue;
                    }
                    if (hasNum[board[row][col] - '1'] == true) {
                        return false;
                    }
                    hasNum[board[row][col] - '1'] = true;
                }
                if ((row + 1) % 3 == 0) {
                    reset(hasNum);
                }
            }
        }
        return true;
    }
};
