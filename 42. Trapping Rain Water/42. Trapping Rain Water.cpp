/*
 * Problem: 42. Trapping Rain Water
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/trapping-rain-water/
 * Language: cpp
 * Date: 2026-06-06
 */

class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> left(n), right(n);
        for (int i = 1; i < n; i++) {
            left[i] = max(h[i - 1], left[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(h[i + 1], right[i + 1]);
        }
        int count = 0;
        for (int i = 1; i < n - 1; i++) {
            if (left[i] > h[i] && right[i] > h[i]) {
                count += min(left[i], right[i]) - h[i];
            }
        }
        return count;
    }
};
