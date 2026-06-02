/*
 * Problem: 287. Find the Duplicate Number
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-the-duplicate-number/submissions/2019889996/
 * Language: cpp
 * Date: 2026-06-02
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Find intersection point
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Find entrance of the cycle
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
