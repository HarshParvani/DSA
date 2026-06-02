/*
 * Problem: 1658. Minimum Operations to Reduce X to Zero
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/submissions/2020002075/
 * Language: cpp
 * Date: 2026-06-02
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        if (target < 0) return -1;

        int n = nums.size();
        int left = 0, currSum = 0, maxLen = -1;

        for (int right = 0; right < n; right++) {
            currSum += nums[right];
            while (left <= right && currSum > target) {
                currSum -= nums[left++];
            }
            if (currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        return (maxLen == -1) ? -1 : n - maxLen;
    }
};

