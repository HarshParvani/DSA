/*
 * Problem: 19. Remove Nth Node From End of List
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 * Language: cpp
 * Date: 2026-05-26
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers
        while(fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Delete node
        slow->next = slow->next->next;

        return dummy->next;
    }
};

