/*
 * Problem: 445. Add Two Numbers II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/add-two-numbers-ii/submissions/2021114215/
 * Language: cpp
 * Date: 2026-06-03
 */

class Solution {
public:

    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverse(l1);
        l2 = reverse(l2);

        int carry = 0;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(l1 || l2 || carry) {

            int sum = carry;

            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return reverse(dummy.next);
    }
};
