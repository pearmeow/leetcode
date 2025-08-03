/**
 * @file 54-spiral-matrix.cpp
 * @author Perry Huang
 * @date 2025-08-03
 * 54. Spiral Matrix
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 */

#include <vector>

const size_t RIGHT = 0;
const size_t DOWN = 1;
const size_t LEFT = 2;
const size_t UP = 3;

class Solution {
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        std::vector<size_t> limits = {matrix[0].size(), matrix.size(), 0, 0};
        size_t direction = RIGHT;
        if (matrix[0].size() == 1) {
            direction = DOWN;
        }
        size_t x = 0;
        size_t y = 0;
        res.push_back(matrix[x][y]);
        while (!done_traversing(limits, direction, x, y)) {
            switch (direction) {
                case RIGHT:
                    while (y + 1 < limits[direction]) {
                        ++y;
                        res.push_back(matrix[x][y]);
                    }
                    ++limits[UP];
                    break;
                case DOWN:
                    while (x + 1 < limits[direction]) {
                        ++x;
                        res.push_back(matrix[x][y]);
                    }
                    --limits[RIGHT];
                    break;
                case LEFT:
                    while (y > limits[direction]) {
                        --y;
                        res.push_back(matrix[x][y]);
                    }
                    --limits[DOWN];
                    break;
                case UP:
                    while (x > limits[direction]) {
                        --x;
                        res.push_back(matrix[x][y]);
                    }
                    ++limits[LEFT];
                    break;
            }
            direction = (direction + 1) % 4;
        }
        return res;
    }
    bool done_traversing(const std::vector<size_t>& limits, const size_t direction, size_t x, size_t y) {
        switch (direction) {
            case RIGHT:
                return y + 1 >= limits[RIGHT];
                break;
            case DOWN:
                return x + 1 >= limits[DOWN];
                break;
            case LEFT:
                return y <= limits[LEFT];
                break;
            case UP:
                return x <= limits[UP];
                break;
        }
        return false;
    }
};
