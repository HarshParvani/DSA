/*
 * Problem: 96. Unique Binary Search Trees
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/unique-binary-search-trees/submissions/2026078844/
 * Language: cpp
 * Date: 2026-06-08
 */

class Solution {
public:
    int numTrees(int n) {
        long fact =1;
        for(int i=0;i<n;i++){
            fact=fact*(n*2-i);
            fact=fact/(i+1);
        }
        return fact/(n+1);
    }
};
