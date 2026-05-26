/*
 * Problem: 206. Reverse Linked List
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/reverse-linked-list/submissions/
 * Language: cpp
 * Date: 2026-05-26
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL) {

            ListNode* forward = curr->next;

            curr->next = prev;

            prev = curr;

            curr = forward;
        }

        return prev;
    }
};
