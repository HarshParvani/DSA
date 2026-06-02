/*
 * Problem: 561. Array Partition
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/array-partition/submissions/2019901786/
 * Language: cpp
 * Date: 2026-06-02
 */

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        for (int i=0;i<nums.size();i+=2){
            sum+=nums[i];
        }
        return sum;
    }
};
