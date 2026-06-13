/*
 * Problem: 213. House Robber II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/house-robber-ii/submissions/2031626514/
 * Language: cpp
 * Date: 2026-06-13
 */

class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int> profit1(n, 0);
        vector<int> profit2(n, 0);

        profit1[0] = nums[0];

        for(int i = 1; i < n - 1; i++) {

            int rob = nums[i];

            if(i > 1)
                rob += profit1[i - 2];

            int notRob = profit1[i - 1];

            profit1[i] = max(rob, notRob);
        }

        profit2[1] = nums[1];

        for(int i = 2; i < n; i++) {

            int rob = nums[i];

            if(i > 2)
                rob += profit2[i - 2];

            int notRob = profit2[i - 1];

            profit2[i] = max(rob, notRob);
        }

        return max(profit1[n - 2], profit2[n - 1]);
    }
};
