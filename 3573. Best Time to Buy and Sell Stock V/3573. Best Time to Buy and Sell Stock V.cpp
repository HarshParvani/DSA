/*
 * Problem: 3573. Best Time to Buy and Sell Stock V
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/submissions/2033803605/
 * Language: cpp
 * Date: 2026-06-15
 */

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

class Solution {
    ll helper(vector<int>& prices, int day, int state, int k, vvvi& memo) {
        if (day == prices.size()) {
            if(state == 0)  return 0;
            return -1e18;
        }
        if (k == 0)
            return 0;
        if (memo[day][state][k] != -1)
            return memo[day][state][k];
        ll profit = 0;
        if (state == 0) {
            ll buy = -prices[day] + helper(prices, day + 1, 1, k, memo);
            ll shortSell = prices[day] + helper(prices, day + 1, 2, k, memo);
            ll skip = helper(prices, day + 1, 0, k, memo);
            profit = max({buy, skip, shortSell});
        } else if (state == 1) {
            ll sell = prices[day] + helper(prices, day + 1, 0, k - 1, memo);
            ll skip = helper(prices, day + 1, 1, k, memo);
            profit = max(sell, skip);
        } else {
            ll buyItBack =
                -prices[day] + helper(prices, day + 1, 0, k - 1, memo);
            ll skip = helper(prices, day + 1, 2, k, memo);
            profit = max(buyItBack, skip);
        }
        return memo[day][state][k] = profit;
    }

public:
    ll maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vvvi memo(n + 2, vvi(3, vi(k + 1, -1)));
        return helper(prices, 0, 0, k, memo);
    }
};
