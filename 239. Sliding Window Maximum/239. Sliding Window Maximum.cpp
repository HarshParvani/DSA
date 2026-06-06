/*
 * Problem: 239. Sliding Window Maximum
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/sliding-window-maximum/submissions/2024023892/
 * Language: cpp
 * Date: 2026-06-06
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        deque<int> dq;
        int left = 0, right = 0;
        vector<int> ans;
        while (right < arr.size()) {
            if (!dq.empty() && dq.front() < left) {
                dq.pop_front();
            }
            while (!dq.empty() && arr[dq.back()] <= arr[right]) {
                dq.pop_back();
            }
            dq.push_back(right);
            if (right - left + 1 == k) {
                ans.push_back(arr[dq.front()]);
                left++;
            }

            right++;
        }
        return ans;
    }
};
