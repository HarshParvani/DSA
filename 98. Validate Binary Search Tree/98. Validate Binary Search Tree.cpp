/*
 * Problem: 98. Validate Binary Search Tree
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/validate-binary-search-tree/
 * Language: cpp
 * Date: 2026-06-06
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    bool solve(TreeNode* root, long min, long max) {
        if (root == nullptr)
            return true;
        if (root->val <= min || root->val >= max) {
            return false;
        }
        return solve(root->left, min, root->val) &&
               solve(root->right, root->val, max);
    }

public:
    bool isValidBST(TreeNode* root) { return solve(root, LONG_MIN, LONG_MAX); }
};
