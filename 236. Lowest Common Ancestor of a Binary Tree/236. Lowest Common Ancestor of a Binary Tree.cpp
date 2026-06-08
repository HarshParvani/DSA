/*
 * Problem: 236. Lowest Common Ancestor of a Binary Tree
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/2026242182/
 * Language: cpp
 * Date: 2026-06-08
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr)
            return root;
        if(root==p)
            return root;
        if(root==q)
            return root;
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        if(left==nullptr)
            return right;
        else if(right==nullptr)
            return left;
        else
            return root;
    }
};
