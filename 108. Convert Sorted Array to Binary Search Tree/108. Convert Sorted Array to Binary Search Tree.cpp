/*
 * Problem: 108. Convert Sorted Array to Binary Search Tree
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/2024057503/
 * Language: cpp
 * Date: 2026-06-06
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
    TreeNode* solve(vector<int>&arr,int low,int high){
        if(high<low){
            return nullptr;
        }
        int mid=low+(high-low)/2;
        TreeNode *root= new TreeNode(arr[mid]);
        root->left=solve(arr,low,mid-1);
        root->right=solve(arr,mid+1,high);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& arr) {
        return solve (arr,0,arr.size()-1);
    }
};
