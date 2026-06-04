/*
 * Problem: 2181. Merge Nodes in Between Zeros
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/submissions/2022107933/
 * Language: cpp
 * Date: 2026-06-04
 */

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

        ListNode dummy(0);
        ListNode* ptr = &dummy;

        head = head->next;   // skip first zero
        int sum = 0;

        while (head) {
            if (head->val == 0) {
                ptr->next = new ListNode(sum);
                ptr = ptr->next;
                sum = 0;
            } else {
                sum += head->val;
            }

            head = head->next;
        }

        return dummy.next;
    }
};
