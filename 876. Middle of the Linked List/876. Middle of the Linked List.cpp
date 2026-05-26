/*
 * Problem: 876. Middle of the Linked List
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/middle-of-the-linked-list/submissions/2013497917/
 * Language: cpp
 * Date: 2026-05-26
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
