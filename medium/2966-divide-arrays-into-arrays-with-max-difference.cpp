/**
 * @file 2966-divide-arrays-into-arrays-with-max-difference.cpp
 * @author Perry Huang
 * @date 2025-06-18
 */

#include <algorithm>
#include <vector>

std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
    std::vector<bool> taken(nums.size(), false);
    std::vector<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i + 2 < nums.size(); i += 3) {
        if (nums[i + 2] - nums[i] > k) {
            return {};
        } else {
            res.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
    }
    return res;
}
