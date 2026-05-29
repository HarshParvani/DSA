/*
 * Problem: 144. Binary Tree Preorder Traversal
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/binary-tree-preorder-traversal/submissions/2016210440/
 * Language: cpp
 * Date: 2026-05-29
 */

class Solution {
public:
    
    void preorder(TreeNode* root, vector<int>& ans) {
        
        if(root == NULL)
            return;

        ans.push_back(root->val);   // Root
        
        preorder(root->left, ans);   // Left
        
        preorder(root->right, ans);  // Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        preorder(root, ans);
        
        return ans;
    }
};
