/*
 * Problem: 215. Kth Largest Element in an Array
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/2015349080/
 * Language: cpp
 * Date: 2026-05-28
 */

class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int i = 0; i < nums.size(); i++) {

            min_heap.push(nums[i]);

            // Keep heap size = k
            if(min_heap.size() > k) {
                min_heap.pop();
            }
        }

        return min_heap.top();
    }
};
