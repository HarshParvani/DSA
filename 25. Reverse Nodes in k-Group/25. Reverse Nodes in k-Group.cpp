/*
 * Problem: 25. Reverse Nodes in k-Group
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/2022131156/
 * Language: cpp
 * Date: 2026-06-04
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;

        while (true) {

            // Find kth node
            ListNode* kth = prevGroup;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }

            if (!kth) break;

            ListNode* groupNext = kth->next;

            // Reverse current group
            ListNode* prev = groupNext;
            ListNode* curr = prevGroup->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Connect groups
            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;
            prevGroup = temp;
        }

        return dummy.next;
    }
};
