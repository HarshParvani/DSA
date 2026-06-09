/*
 * Problem: 987. Vertical Order Traversal of a Binary Tree
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/2027240289/
 * Language: cpp
 * Date: 2026-06-09
 */

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, multiset<int>>> mp;

        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {

            auto pairs = q.front();
            q.pop();

            TreeNode* curr = pairs.first;
            int col = pairs.second.first;
            int row = pairs.second.second;

            mp[col][row].insert(curr->val);

            if (curr->left) {
                q.push({curr->left, {col - 1, row + 1}});
            }

            if (curr->right) {
                q.push({curr->right, {col + 1, row + 1}});
            }
        }

        vector<vector<int>> ans;

        for (auto& p : mp) {

            vector<int> temp;

            for (auto& q : p.second) {

                temp.insert(temp.end(), q.second.begin(), q.second.end());
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
