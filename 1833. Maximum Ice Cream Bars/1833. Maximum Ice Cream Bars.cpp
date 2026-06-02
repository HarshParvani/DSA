/*
 * Problem: 1833. Maximum Ice Cream Bars
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-ice-cream-bars/submissions/2019925472/
 * Language: cpp
 * Date: 2026-06-02
 */

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count = 0;
        for(int i=0;i<costs.size();i++){
            if(coins>=costs[i]){
            coins=coins-costs[i];
            count++;
            }
        }
        return count;
    }
};
