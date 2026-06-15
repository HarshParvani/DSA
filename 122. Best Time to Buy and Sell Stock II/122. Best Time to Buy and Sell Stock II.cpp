/*
 * Problem: 122. Best Time to Buy and Sell Stock II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/2033671200/
 * Language: cpp
 * Date: 2026-06-15
 */

using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
    int helper(vi& prices, int day, int state, vvi&memo) {
        if (day == prices.size())
            return 0;
        if(memo[day][state] != -1)
            return memo[day][state];
        int profit = 0;
        if (state == 0) {
            int buy = -prices[day] + helper(prices, day + 1, 1, memo);
            int skip = helper(prices, day + 1, 0, memo);
            profit = max(buy, skip);
        } else {
            int sell = prices[day] + helper(prices, day + 1, 0, memo);
            int skip = helper(prices, day + 1, 1, memo);
            profit = max(sell, skip);
        }
        return memo[day][state] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vvi memo(n+1, vi(2, -1));
        return helper(prices, 0, 0, memo);
    }
};
