/*
 * Problem: 503. Next Greater Element II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/next-greater-element-ii/submissions/2023079093/
 * Language: cpp
 * Date: 2026-06-05
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }

            if (i < n) {
                if (!st.empty()) {
                    ans[i] = st.top();
                }
            }

            st.push(nums[i % n]);
        }

        return ans;
    }
};

