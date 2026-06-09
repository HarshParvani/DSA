/*
 * Problem: Unknown Problem
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/merge-bsts-to-create-single-bst/submissions/2027380907/
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    unordered_map<int, TreeNode*> roots;

    bool dfs(TreeNode* root,long mn,long mx) {

        if(!root) return true;

        if(root->val <= mn || root->val >= mx)
            return false;

        if(!root->left &&
           !root->right &&
           roots.count(root->val)) {

            TreeNode* mergeNode = roots[root->val];

            roots.erase(root->val);

            root->left = mergeNode->left;
            root->right = mergeNode->right;
        }

        return dfs(root->left,mn,root->val) &&
               dfs(root->right,root->val,mx);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) {

        unordered_map<int,int> freq;

        for(auto root : trees) {

            roots[root->val] = root;

            if(root->left)
                freq[root->left->val]++;

            if(root->right)
                freq[root->right->val]++;
        }

        TreeNode* start = nullptr;

        for(auto root : trees) {

            if(freq[root->val] == 0) {
                start = root;
                break;
            }
        }

        if(!start) return nullptr;

        roots.erase(start->val);

        if(!dfs(start,LONG_MIN,LONG_MAX))
            return nullptr;

        if(!roots.empty())
            return nullptr;

        return start;
    }
};
