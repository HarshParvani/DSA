/*
 * Problem: 94. Binary Tree Inorder Traversal
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/2016208037/
 * Language: cpp
 * Date: 2026-05-29
 */

class Solution {
public:
    
    void inorder(TreeNode* root, vector<int>& ans) {
        
        if(root == NULL)
            return;
        
        inorder(root->left, ans);   // Left
        
        ans.push_back(root->val);   // Root
        
        inorder(root->right, ans);  // Right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        inorder(root, ans);
        
        return ans;
    }
};
