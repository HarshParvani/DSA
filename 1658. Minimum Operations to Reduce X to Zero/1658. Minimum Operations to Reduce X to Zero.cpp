/*
 * Problem: 1658. Minimum Operations to Reduce X to Zero
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/submissions/2019999139/
 * Language: cpp
 * Date: 2026-06-02
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
    int n=nums.size();
    int totalsum =0;
    for (int i:nums)
    totalsum+=i;
    int reqsum=totalsum-x;
    int winsum=0;
    int len=-1;
    int left =0,right=0;
    while (right <n){
        winsum+=nums[right];
        while(left<=right && winsum>reqsum){
            winsum-=nums[left];
            left++;
        }
        if(winsum==reqsum){
            len = max(right-left+1,len);
        }
        right++;
    }
    return len == -1?-1:n-len;
    }
};
