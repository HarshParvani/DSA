/*
 * Problem: 198. House Robber
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/house-robber/submissions/2031594121/
 * Language: cpp
 * Date: 2026-06-13
 */

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n);

        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {

            int pick = nums[i];

            if(i > 1)
                pick += dp[i - 2];

            int notPick = dp[i - 1];

            dp[i] = max(pick, notPick);
        }

        return dp[n - 1];
    }
};
