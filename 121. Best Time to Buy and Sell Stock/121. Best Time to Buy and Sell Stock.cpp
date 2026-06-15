/*
 * Problem: 121. Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/2033615801/
 * Language: cpp
 * Date: 2026-06-15
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int buy =prices[0],ans=0;
      for(int i:prices){
        ans=max(i-buy,ans);
        buy=min(buy,i);
      }  
      return ans;
    }
};
