/*
 * Problem: 525. Contiguous Array
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/contiguous-array/submissions/2018851813/
 * Language: cpp
 * Date: 2026-06-01
 */

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 1)
                sum++;
            else
                sum--;

            if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            }
            else {
                mp[sum] = i;
            }
        }

        return maxi;
    }
};
