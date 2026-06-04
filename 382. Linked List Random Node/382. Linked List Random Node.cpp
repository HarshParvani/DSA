/*
 * Problem: 382. Linked List Random Node
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/linked-list-random-node/submissions/2022169477/
 * Language: cpp
 * Date: 2026-06-04
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
private:
    vector<int> nums;

public:
    Solution(ListNode* head) {
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        int idx = rand() % nums.size();
        return nums[idx];
    }
};
