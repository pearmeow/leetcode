/**
 * @file 108-convert-sorted-array-to-binary-search-tree.cpp
 * @author Perry Huang
 * @date 2024-04-11
 * 108. Convert Sorted Array to Binary Search Tree
 * Given an integer array nums where the elements are sorted in ascending order,
 * convert it to a height-balanced binary search tree.
 */

#include <vector>

class Solution {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }

    TreeNode* helper(std::vector<int>& nums, int start, int end) {
        if (end <= start) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(nums[mid], helper(nums, start, mid), helper(nums, mid + 1, end));
        return node;
    }
};
