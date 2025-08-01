/**
 * @file 118-pascals-triangle.cpp
 * @author Perry Huang
 * @date 2025-07-31
 * 118. Pascal's Triangle
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 */

#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res;
        res.emplace_back(1, 1);
        int row = 0;
        while (row != numRows - 1) {
            res.emplace_back(1, 1);
            for (size_t i = 0; i < res[row].size() - 1; ++i) {
                res[row + 1].push_back(res[row][i] + res[row][i + 1]);
            }
            res[row + 1].push_back(1);
            ++row;
        }
        return res;
    }
};
