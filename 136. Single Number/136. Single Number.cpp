/*
 * Problem: 136. Single Number
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/single-number/submissions/2030653924/
 * Language: cpp
 * Date: 2026-06-12
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;

        for(int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};
