/*
 * Problem: 124. Binary Tree Maximum Path Sum
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/2027367656/
 * Language: cpp
 * Date: 2026-06-09
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
    int solve(TreeNode* root, int& maxSum) {
        if (root == nullptr)
            return 0;
       int left= max(solve(root->left,maxSum),0);
        int right= max(solve(root->right,maxSum),0);
        maxSum=max(maxSum,left+right+root->val);
        return max(left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
         int maxSum = INT_MIN; 
         solve(root,maxSum);
         return maxSum;
         }
};
