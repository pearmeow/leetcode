/**
 * @file 1372-longest-zigzag-path-in-a-binary-tree.cpp
 * @author Perry Huang
 * @date 2025-06-10
 * 1372. Longest ZigZag Path in a Binary Tree
 * You are given the root of a binary tree.
 * A ZigZag path for a binary tree is defined as follow:
 * Choose any node in the binary tree and a direction (right or left).
 * If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
 * Change the direction from right to left or from left to right.
 * Repeat the second and third steps until you can't move in the tree.
 * Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
 * Return the longest ZigZag path contained in that tree.
 */

#include <algorithm>
#include <tuple>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::tuple<int, int, int> helper(TreeNode* root) {
    if (root == nullptr) return {-1, -1, -1};
    std::tuple<int, int, int> left = helper(root->left);
    std::tuple<int, int, int> right = helper(root->right);
    int maxLeft = std::get<1>(left) + 1;
    int maxRight = std::get<0>(right) + 1;
    int maxInTree = std::max(std::max(std::get<2>(left), std::get<2>(right)), std::max(maxLeft, maxRight));
    return {maxLeft, maxRight, maxInTree};
}

int longestZigZag(TreeNode* root) {
    if (root == nullptr) return 0;
    std::tuple<int, int, int> left = helper(root->left);
    std::tuple<int, int, int> right = helper(root->right);
    int maxLeft = std::get<1>(left) + 1;
    int maxRight = std::get<0>(right) + 1;
    int maxInTree = std::max(std::max(std::get<2>(left), std::get<2>(right)), std::max(maxLeft, maxRight));
    return maxInTree;
}
