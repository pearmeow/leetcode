/**
 * @file 450-delete-node-in-a-bst.cpp
 * @author Perry Huang
 * @date 2025-06-13
 * 450. Delete Node in a BST
 * Given a root node reference of a BST and a key, delete the node with the given key in the BST.
 * Return the root node reference (possibly updated) of the BST.
 * Basically, the deletion can be divided into two stages:
 * Search for a node to remove.
 * If the node is found, delete the node.
 */

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

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        TreeNode* prev = nullptr;
        TreeNode* head = root;
        while (head != nullptr) {
            if (head->val == key) {
                break;
            } else if (head->val < key) {
                prev = head;
                head = head->right;
            } else {
                prev = head;
                head = head->left;
            }
        }
        if (head == nullptr) return root;
        if (head->left != nullptr && head->right != nullptr) {
            // always go left!
            prev = head;
            TreeNode* swap = head->left;
            while (swap->right != nullptr) {
                prev = swap;
                swap = swap->right;
            }
            head->val = swap->val;
            if (prev == head) {
                prev->left = swap->left;
            } else {
                prev->right = swap->left;
            }
        } else if (head->left != nullptr) {
            if (prev == nullptr) {  // root case
                return head->left;
            }
            if (prev->left != nullptr) {
                if (prev->left->val == key) {
                    prev->left = head->left;
                } else {
                    prev->right = head->left;
                }
            } else {
                prev->right = head->left;
            }
        } else if (head->right != nullptr) {
            if (prev == nullptr) {  // root case
                return head->right;
            }
            if (prev->left != nullptr) {
                if (prev->left->val == key) {
                    prev->left = head->right;
                } else {
                    prev->right = head->right;
                }
            } else {
                prev->right = head->right;
            }
        } else {
            if (prev == nullptr) {  // root case
                return nullptr;
            }
            if (prev->left != nullptr) {
                if (prev->left->val == key) {
                    prev->left = nullptr;
                } else {
                    prev->right = nullptr;
                }
            } else {
                prev->right = nullptr;
            }
        }
        return root;
    }
};
