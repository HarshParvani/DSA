/*
 * Problem: 2181. Merge Nodes in Between Zeros
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/submissions/2022060701/
 * Language: cpp
 * Date: 2026-06-04
 */

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head->next;
        ListNode* temp = head->next;

        int sum = 0;

        while (temp) {
            if (temp->val != 0) {
                sum += temp->val;
            } else {
                modify->val = sum;
                sum = 0;

                if (temp->next) {
                    modify->next = temp->next;
                    modify = modify->next;
                }
            }
            temp = temp->next;
        }

        modify->next = nullptr;
        return head->next;
    }
};
