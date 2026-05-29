/*
 * Problem: 145. Binary Tree Postorder Traversal
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/2016211970/
 * Language: cpp
 * Date: 2026-05-29
 */

class Solution {
public:
    
    void postorder(TreeNode* root, vector<int>& ans) {
        
        if(root == NULL)
            return;
        
        postorder(root->left, ans);   // Left
        
        postorder(root->right, ans);  // Right
        
        ans.push_back(root->val);   // Root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        postorder(root, ans);
        
        return ans;
    }
};
