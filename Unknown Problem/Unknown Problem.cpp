/*
 * Problem: Unknown Problem
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/palindrome-linked-list/submissions/2013492792/
 * Language: cpp
 * Date: 2026-05-26
 */

class Solution {
public:

    // Reverse linked list
    ListNode* reverse(ListNode* head) {

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

    bool isPalindrome(ListNode* head) {

        // Single node
        if(head == NULL || head->next == NULL) {
            return true;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL &&
              fast->next->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        slow->next = reverse(slow->next);

        // Compare halves
        ListNode* first = head;
        ListNode* second = slow->next;

        while(second != NULL) {

            if(first->val != second->val) {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
