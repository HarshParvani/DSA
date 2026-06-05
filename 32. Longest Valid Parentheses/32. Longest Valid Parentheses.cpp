/*
 * Problem: 32. Longest Valid Parentheses
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/longest-valid-parentheses/submissions/2023116742/
 * Language: cpp
 * Date: 2026-06-05
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int len=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
            st.push(i);
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    len=max(len,i-st.top());
                }
            }
        }
        return len;
    }
};
