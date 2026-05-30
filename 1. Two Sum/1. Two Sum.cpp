/*
 * Problem: 1. Two Sum
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/two-sum/submissions/2017550970/
 * Language: cpp
 * Date: 2026-05-30
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>output;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(target==nums[i]+nums[j]){
                    output.push_back(i);
                    output.push_back(j);
                }
            }
        }
        return output;
    }
};
