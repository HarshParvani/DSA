/*
 * Problem: 102. Binary Tree Level Order Traversal
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/2016229226/
 * Language: cpp
 * Date: 2026-05-29
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();      // nodes at current level
            vector<int> level;

            for(int i = 0; i < size; i++) {

                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if(node->left)
                    q.push(node->left);

                if(node->right)
                    q.push(node->right);
            }

            ans.push_back(level);
        }

        return ans;
    }
};
