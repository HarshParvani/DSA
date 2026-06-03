/*
 * Problem: 4. Median of Two Sorted Arrays
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/2021077738/
 * Language: cpp
 * Date: 2026-06-03
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        // Always binary search on smaller array
        if(n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0;
        int high = n;

        int total = n + m;
        int half = (total + 1) / 2;

        while(low <= high) {

            int i = low + (high - low) / 2;
            int j = half - i;

            int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == n) ? INT_MAX : nums1[i];

            int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == m) ? INT_MAX : nums2[j];

            if(left1 <= right2 && left2 <= right1) {

                if(total % 2 == 0) {
                    return (max(left1, left2) +
                            min(right1, right2)) / 2.0;
                }

                return max(left1, left2);
            }

            else if(left1 > right2) {
                high = i - 1;
            }

            else {
                low = i + 1;
            }
        }

        return 0.0;
    }
};
