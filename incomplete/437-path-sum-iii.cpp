/**
 * @file 437-path-sum-iii.cpp
 * @author Perry Huang
 * @date 2025-06-08
 * 437. Path Sum III
 * Given the root of a binary tree and an integer targetSum, return the number of paths
 * where the sum of the values along the path equals targetSum.
 * The path does not need to start or end at the root or a leaf, but it must go downwards
 * (i.e., traveling only from parent nodes to child nodes).
 */

#include <unordered_map>

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    std::pair<std::unordered_map<long, long>, long> helper(TreeNode* root, long targetSum) {
        std::pair<std::unordered_map<long, long>, long> left;
        std::pair<std::unordered_map<long, long>, long> right;
        long target = targetSum - root->val;
        long total = 0;
        if (target == 0) {
            ++total;
        }
        if (root->left != nullptr) {
            left = helper(root->left, targetSum);
            total += left.second;
            if (left.first.find(target) != left.first.end()) {
                total += left.first[target];
            }
        }
        if (root->right != nullptr) {
            right = helper(root->right, targetSum);
            total += right.second;
            if (right.first.find(target) != right.first.end()) {
                total += right.first[target];
            }
        }
        std::unordered_map<long, long> perms;
        for (const auto& [key, val] : left.first) {
            perms[key + root->val] = val;
        }
        for (const auto& [key, val] : right.first) {
            if (perms.find(key + root->val) == perms.end()) {
                perms[key + root->val] = val;
            } else {
                perms[key + root->val] += val;
            }
        }
        if (perms.find(root->val) == perms.end()) {
            perms[root->val] = 1;
        } else {
            ++perms[root->val];
        }
        return std::make_pair(perms, total);
    }

    int pathSum(TreeNode* root, long targetSum) {
        if (root == nullptr) {
            return 0;
        }
        std::pair<std::unordered_map<long, long>, long> res = helper(root, targetSum);
        return res.second;
    }
};
