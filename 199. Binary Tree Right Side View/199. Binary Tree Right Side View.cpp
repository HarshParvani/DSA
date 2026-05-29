/*
 * Problem: 199. Binary Tree Right Side View
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/binary-tree-right-side-view/submissions/2016272486/
 * Language: cpp
 * Date: 2026-05-29
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        vector<int> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                TreeNode* curr = q.front();
                q.pop();

                if(i == size - 1)
                    ans.push_back(curr->val);

                if(curr->left)
                    q.push(curr->left);

                if(curr->right)
                    q.push(curr->right);
            }
        }

        return ans;
    }
};
