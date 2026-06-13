/*
 * Problem: 120. Triangle
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/triangle/submissions/2031561991/
 * Language: cpp
 * Date: 2026-06-13
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j = 0; j < n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        for(int i = n - 2; i >= 0; i--) {

            for(int j = 0; j <= i; j++) {

                dp[i][j] =
                    triangle[i][j] +
                    min(dp[i+1][j],
                        dp[i+1][j+1]);
            }
        }

        return dp[0][0];
    }
};
