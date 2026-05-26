/*
 * Problem: 21. Merge Two Sorted Lists
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/merge-two-sorted-lists/description/
 * Language: cpp
 * Date: 2026-05-26
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(list1 != NULL && list2 != NULL) {

            if(list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }

            tail = tail->next;
        }

        // Remaining nodes
        if(list1 != NULL) {
            tail->next = list1;
        }

        if(list2 != NULL) {
            tail->next = list2;
        }

        return dummy.next;
    }
};
