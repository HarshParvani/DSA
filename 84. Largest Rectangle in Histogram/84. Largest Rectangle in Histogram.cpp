/*
 * Problem: 84. Largest Rectangle in Histogram
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/2023148393/
 * Language: cpp
 * Date: 2026-06-05
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size();
        stack<int>st1;
        vector<int> left(n),right(n);
        for(int i=0;i<n;i++){
            while(!st1.empty() && arr[st1.top()]>=arr[i]){
                st1.pop();
            }
            if(st1.empty()){
                left[i]=-1;
            }
            else{
                left[i]=st1.top();
            }
            st1.push(i);
        }
        stack<int>st2;
        for(int i=n-1;i>=0;i--){
            while(!st2.empty() && arr[st2.top()]>=arr[i]){
                st2.pop();
            }
            if(st2.empty()){
                right[i]=n;
            }
            else{
                right[i]=st2.top();
            }
            st2.push(i);
        }
        int maxArea=0;
        for(int i=0;i<n;i++){
            int area =(right[i]-left[i]-1)*arr[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;

    }
};
