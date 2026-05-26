/*
 * Problem: 141. Linked List Cycle
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/linked-list-cycle/description/
 * Language: cpp
 * Date: 2026-05-26
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            // Cycle detected
            if(slow == fast) {
                return true;
            }
        }

        return false;
    }
};
