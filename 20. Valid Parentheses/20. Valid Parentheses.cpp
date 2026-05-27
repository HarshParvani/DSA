/*
 * Problem: 20. Valid Parentheses
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/valid-parentheses/submissions/2014413751/
 * Language: cpp
 * Date: 2026-05-27
 */

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char ch : s) {

            // Opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // Closing brackets
            else {

                // stack empty means no opening bracket
                if(st.empty()) {
                    return false;
                }

                // check matching
                if((ch == ')' && st.top() == '(') ||
                   (ch == '}' && st.top() == '{') ||
                   (ch == ']' && st.top() == '[')) {

                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        // stack should be empty
        return st.empty();
    }
};
