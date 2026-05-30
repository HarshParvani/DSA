/*
 * Problem: 283. Move Zeroes
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/move-zeroes/submissions/2017105095/
 * Language: cpp
 * Date: 2026-05-30
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;  // Position for next non-zero
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
