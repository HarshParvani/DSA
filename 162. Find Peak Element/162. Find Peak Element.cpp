/*
 * Problem: 162. Find Peak Element
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-peak-element/description/
 * Language: cpp
 * Date: 2026-06-01
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int max=0;
        for (int i=0;i<nums.size();i++){
            if(nums[max]<nums[i]){
                max=i;
            }
        }
        return max;
    }
};
