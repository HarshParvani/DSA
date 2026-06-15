/*
 * Problem: 121. Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 * Language: cpp
 * Date: 2026-06-15
 */

class Solution {
    int helper(vector<int>& prices, int day, int state) {

        if (day == prices.size())
            return 0;
        int profit = 0;

        if (state == 0) {
            int buy = -prices[day] + helper(prices, day + 1, 1);
            int skip = helper(prices, day + 1, 0);
            profit = max(buy, skip);
        } else {
            int sell = prices[day] + helper(prices, day + 1, 0);
            int skip = helper(prices, day + 1, 1);
            profit = max(sell, skip);
        }
        return profit;
    }
    public:
    int maxProfit(vector<int>& prices){ 
        
        return helper(prices, 0, 0); 
        }
};
