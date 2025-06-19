/**
 * @file 2294-partition-array-such-that-maximum-difference-is-k.cpp
 * @author Perry Huang
 * @date 2025-06-18
 */

#include <vector>
#include <algorithm>

int partitionArray(std::vector<int>& nums, int k) {
    std::sort(nums.begin(), nums.end());
    size_t least = nums[0];
    size_t partitions = 1;
    for (int i : nums) {
        if (i - least > k) {
            least = i;
            ++partitions;
        }
    }
    return partitions;
}
