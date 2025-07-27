/**
 * @file 84-largest-rectangle-in-histogram.cpp
 * @author Perry Huang
 * @date 2025-07-22
 * 84. Largest Rectangle in Histogram
 * Given an array of integers heights representing the histogram's bar height where the width of each bar is 1,
 * return the area of the largest rectangle in the histogram.
 */

#include <stack>
#include <vector>

class Solution {
   public:
    struct dimensions {
        int length = 0;
        int width = 0;
    };

    int largestRectangleArea(const std::vector<int>& heights) {
        std::stack<dimensions> monInc;
        int res = 0;
        int addedWidth = 0;
        for (int i : heights) {
            addedWidth = 0;
            while (!monInc.empty() && i < monInc.top().length) {
                addedWidth += monInc.top().width;
                res = std::max(res, monInc.top().length * addedWidth);
                monInc.pop();
            }
            monInc.push({.length = i, .width = 1 + addedWidth});
        }
        addedWidth = 0;
        while (!monInc.empty()) {
            addedWidth += monInc.top().width;
            res = std::max(res, monInc.top().length * addedWidth);
            monInc.pop();
        }
        return res;
    }
};
