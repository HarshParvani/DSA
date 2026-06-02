/*
 * Problem: 1833. Maximum Ice Cream Bars
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-ice-cream-bars/submissions/2019942276/
 * Language: cpp
 * Date: 2026-06-02
 */

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxEle =*max_element(costs.begin(),costs.end());
        vector<int>freq(maxEle+1);
        for(int i:costs){
            freq[i]++;
        }
        int count=0;
        for(int i=0;i<=maxEle;i++){
            while(freq[i]>0&& coins>=i){
                freq[i]--;
                count++;
                coins-=i;
            }
        }
        return count;
    }
};
