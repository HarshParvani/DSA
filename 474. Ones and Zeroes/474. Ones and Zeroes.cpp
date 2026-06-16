/*
 * Problem: 474. Ones and Zeroes
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/ones-and-zeroes/submissions/2034858297/
 * Language: cpp
 * Date: 2026-06-16
 */

class Solution {
public:

    int helper(vector<string>& strs, int m, int n, int i,vector<vector<vector<int>>>&memo) {
        if (i == strs.size())
            return 0;
        if(memo[i][m][n] != -1 ) return memo[i][m][n];

        int skip = helper(strs, m, n, i + 1,memo);

        int c0 = count(strs[i].begin(), strs[i].end(), '0');
        int c1 = strs[i].size() - c0;

        int pick = 0;
        if (c0 <= m && c1 <= n) {
            pick = 1 + helper(strs, m - c0, n - c1, i + 1,memo);
        }

        return memo[i][m][n] =max(pick, skip);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> memo(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return helper(strs, m, n, 0,memo);
    }
};
