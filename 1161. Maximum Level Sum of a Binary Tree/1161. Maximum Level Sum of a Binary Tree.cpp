/*
 * Problem: 1161. Maximum Level Sum of a Binary Tree
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/submissions/2026182469/
 * Language: cpp
 * Date: 2026-06-08
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int bfs(TreeNode *root){
        queue<TreeNode*>q;
        q.push(root);
        int maxsum =INT_MIN;
        int maxlevel;
        int level=1;
        while(!q.empty()){
            int n =q.size();
            int sum=0;
            while(n--){
                TreeNode* curr =q.front();
                q.pop();
                sum+= curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            if(sum>maxsum){
                maxsum=sum;
                maxlevel=level;

            }
            level++;
        }
        return maxlevel;
    }
public:
    int maxLevelSum(TreeNode* root) {
        return bfs(root);
    }
};
