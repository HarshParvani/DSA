/*
 * Problem: 105. Construct Binary Tree from Preorder and Inorder Traversal
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/submissions/2027336470/
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
    TreeNode* treeBanao(unordered_map<int, int>& mp, vector<int>& inorder,
                        int inSt, int inEnd, vector<int>& preorder, int preSt,
                        int preEnd) {

        if (inSt > inEnd || preSt > preEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preSt]);

        int rootIndex = mp[preorder[preSt]];

        int leftSize = rootIndex - inSt;

        root->left = treeBanao(mp, inorder, inSt, rootIndex - 1, preorder,
                               preSt + 1, preSt + leftSize);

        root->right = treeBanao(mp, inorder, rootIndex + 1, inEnd, preorder,
                                preSt + leftSize + 1, preEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return treeBanao(mp, inorder, 0, inorder.size() - 1, preorder, 0,
                         preorder.size() - 1);
    }
};
