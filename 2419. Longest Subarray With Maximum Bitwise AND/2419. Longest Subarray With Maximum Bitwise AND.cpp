/*
 * Problem: 2419. Longest Subarray With Maximum Bitwise AND
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/submissions/
 * Language: cpp
 * Date: 2026-06-12
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int maxi = *max_element(nums.begin(), nums.end());

        int cnt = 0;
        int ans = 0;

        for(int i : nums) {

            if(i == maxi) {
                cnt++;
                ans = max(ans, cnt);
            }
            else {
                cnt = 0;
            }
        }

        return ans;
    }
};
