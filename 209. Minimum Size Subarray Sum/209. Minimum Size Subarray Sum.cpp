/*
 * Problem: 209. Minimum Size Subarray Sum
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/minimum-size-subarray-sum/submissions/2017940580/
 * Language: cpp
 * Date: 2026-05-31
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length =INT_MAX;
        int left = 0,right=0;
        int sum=0;
        while(right<nums.size()){
            sum += nums[right];
            while(sum>=target){
                length=min(right-left+1,length);
                sum -=nums[left];
                left++;
            }
            right++;
        }
        return length==INT_MAX? 0 : length;
    }
};
