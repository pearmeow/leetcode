/**
 * @file 11-container-with-most-water.cpp
 * @author Perry Huang
 * @date 2024-02-25
 * 11. Container With Most Water
 * You are given an integer array height of length n.
 * There are n vertical lines drawn such that the two endpoints of the ith line are
 * (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a
 * container, such that the container contains the most water. Return the maximum
 * amount of water a container can store. Notice that you may not slant the
 * container.
 */

#include <vector>

class Solution {
   public:
    int maxArea(const std::vector<int>& height) {
        int res = 0, p1 = 0, p2 = height.size() - 1;
        while (p1 != p2) {
            res = std::max(std::min(height[p1], height[p2]) * (p2 - p1), res);
            height[p1] > height[p2] ? --p2 : ++p1;
        }
        return res;
    }
};
