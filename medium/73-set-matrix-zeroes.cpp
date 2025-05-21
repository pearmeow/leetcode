/**
 * @file 73-set-matrix-zeroes.cpp
 * @author Perry Huang
 * @date 2025-05-20
 * 73. Set Matrix Zeroes
 * Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
 * You must do it in place.
 */
#include <vector>
#include <cmath>

void setZeroes(std::vector<std::vector<int>>& matrix) {
  bool x0 = false, y0 = false;
  for (size_t col = 0; col < matrix[0].size(); ++col) {
    if (matrix[0][col] == 0) x0 = true;
  }
  for (size_t row = 0; row < matrix.size(); ++row) {
    if (matrix[row][0] == 0) y0 = true;
  }
  for (size_t row = 1; row < matrix.size(); ++row) {
    for (size_t col = 1; col < matrix[0].size(); ++col) {
      if (matrix[row][col] == 0) {
        matrix[row][0] = 0;
        matrix[0][col] = 0;
      }
    }
  }
  for (size_t col = 1; col < matrix[0].size(); ++col) {
    if (matrix[0][col] == 0) {
      for (size_t row = 1; row < matrix.size(); ++row) matrix[row][col] = 0;
    }
  }
  for (size_t row = 1; row < matrix.size(); ++row) {
    if (matrix[row][0] == 0) {
      for (size_t col = 1; col < matrix[0].size(); ++col) matrix[row][col] = 0;
    }
  }
  if (x0 == true) {
    for (size_t col = 0; col < matrix[0].size(); ++col) {
      matrix[0][col] = 0;
    }
  }
  if (y0 == true) {
    for (size_t row = 0; row < matrix.size(); ++row) {
      matrix[row][0] = 0;
    }
  }
}
