/*
 * Problem: 714. Best Time to Buy and Sell Stock with Transaction Fee
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/
 * Language: cpp
 * Date: 2026-06-15
 */

class Solution {
public:
    int helper(vector<int>& prices, int day, int state, int fee,vector<vector<int>>& memo) {
        if (day == prices.size())
            return 0;

        if (memo[day][state] != -1)
            return memo[day][state];

        int profit = 0;

        if (state == 0) {
            int buy = -prices[day] + helper(prices, day + 1, 1, fee, memo);
            int skip = helper(prices, day + 1, 0, fee, memo);
            profit = max(buy, skip);
        } else {
            int sell =prices[day] - fee + helper(prices, day + 1, 0, fee, memo);
            int skip = helper(prices, day + 1, 1, fee, memo);
            profit = max(sell, skip);
        }
        return memo[day][state] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return helper(prices, 0, 0, fee, memo);
    }
};
