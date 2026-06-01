/*
 * Problem: 540. Single Element in a Sorted Array
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/2018953418/
 * Language: cpp
 * Date: 2026-06-01
 */

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (nums[0] != nums[1])
            return nums[0];

        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            // Found the single element
            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1])
                return nums[mid];

            // We are on the left (proper pairing) side
            if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) ||
                (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
