/*
 * Problem: 1382. Balance a Binary Search Tree
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/balance-a-binary-search-tree/description/
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
    void inorder(TreeNode* root, vector<int>& arr) {

        if (root == NULL)
            return;

        inorder(root->left, arr);

        arr.push_back(root->val);

        inorder(root->right, arr);
    }

    TreeNode* build(vector<int>& arr, int low, int high) {

        if (low > high)
            return NULL;

        int mid = low + (high - low) / 2;

        TreeNode* root = new TreeNode(arr[mid]);

        root->left = build(arr, low, mid - 1);

        root->right = build(arr, mid + 1, high);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {

        vector<int> arr;

        inorder(root, arr);

        return build(arr, 0, arr.size() - 1);
    }
};
