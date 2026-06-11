/*
 * Problem: 547. Number of Provinces
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/number-of-provinces/submissions/2029463234/
 * Language: cpp
 * Date: 2026-06-11
 */

class Solution {
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[u] = true;

        for (auto v : adj[u]) {
            if (!vis[v])
                dfs(v, adj, vis);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1)
                    adj[i].push_back(j);
            }
        }

        vector<bool> vis(n, false);
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis);
                c++;
            }
        }

        return c;
    }
};
