/*
 * Problem: 53. Maximum Subarray
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-subarray/submissions/2017036871/
 * Language: cpp
 * Date: 2026-05-30
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int max_sum=nums[0];
       int curr_sum=0;
       for(int i=0;i<nums.size();i++){
        curr_sum=curr_sum+nums[i];
         max_sum=max(curr_sum,max_sum);
        if(curr_sum<0){
            curr_sum=0;
        }
       }
       return max_sum;
    }
};
