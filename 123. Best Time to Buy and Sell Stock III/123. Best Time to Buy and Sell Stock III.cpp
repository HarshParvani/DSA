/*
 * Problem: 123. Best Time to Buy and Sell Stock III
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 * Language: cpp
 * Date: 2026-06-15
 */

class Solution {
public:
    int helper(vector<int>& prices, int day, int state, int cap,
               vector<vector<vector<int>>>& memo) {
        if (day == prices.size() || cap == 0)
            return 0;
        if (memo[day][state][cap] != -1)
            return memo[day][state][cap];
        int profit = 0;

        if (state == 0) {
            int buy = -prices[day] + helper(prices, day + 1, 1, cap, memo);
            int skip = helper(prices, day + 1, 0, cap, memo);
            profit = max(buy, skip);
        } else {
            int sell = prices[day] + helper(prices, day + 1, 0, cap - 1, memo);
            int skip = helper(prices, day + 1, 1, cap, memo);
            profit = max(sell, skip);
        }
        return memo[day][state][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(prices, 0, 0, 2, memo);
    }
};
