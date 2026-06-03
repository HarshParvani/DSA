/*
 * Problem: 92. Reverse Linked List II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/reverse-linked-list-ii/submissions/2021096851/
 * Language: cpp
 * Date: 2026-06-03
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(head == NULL || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        // Move prev to node before left
        for(int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;

        // Reverse right-left nodes
        for(int i = 0; i < right - left; i++) {

            ListNode* temp = curr->next;

            curr->next = temp->next;

            temp->next = prev->next;

            prev->next = temp;
        }

        return dummy.next;
    }
};
