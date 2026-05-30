/*
 * Problem: 2149. Rearrange Array Elements by Sign
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/submissions/2017127094/
 * Language: cpp
 * Date: 2026-05-30
 */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> pos;
        vector<int> neg;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] > 0) {
                pos.push_back(nums[i]);
            }
            else {
                neg.push_back(nums[i]);
            }
        }

        for(int i = 0; i < pos.size(); i++) {

            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }

        return ans;
    }
};
