/*
 * Problem: 112. Path Sum
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/path-sum/submissions/2024096266/
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
public:
    bool hasPathSum(TreeNode* root, int target) {
        if (root == nullptr)
            return false;
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == target;
        }
        return hasPathSum(root->left, target - root->val) ||
               hasPathSum(root->right, target - root->val);
    }
};
