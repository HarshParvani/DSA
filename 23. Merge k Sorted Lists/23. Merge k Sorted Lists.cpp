/*
 * Problem: 23. Merge k Sorted Lists
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/merge-k-sorted-lists/submissions/2023039632/
 * Language: cpp
 * Date: 2026-06-05
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
    ListNode*mergetwosortedlists(ListNode*left,ListNode*right){
        if(left==nullptr)
            return right;
        if(right==nullptr)
            return left;
        if(left->val<right->val){
            left->next=mergetwosortedlists(left->next,right);
            return left;
        }
        else{
            right->next=mergetwosortedlists(left,right->next);
            return right;
        }
    }
    ListNode* mergesort(vector<ListNode*>&arr,int low ,int high){
        if(low==high){
            return arr[low];
        }
        int mid =low+(high-low)/2;
        ListNode *left=mergesort(arr,low,mid);
        ListNode  *right=mergesort(arr,mid+1,high);
        return mergetwosortedlists(left,right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
        return nullptr;
        return mergesort(lists,0,lists.size()-1);

    }
};
