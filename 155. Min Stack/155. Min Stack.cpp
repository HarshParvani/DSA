/*
 * Problem: 155. Min Stack
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/min-stack/submissions/2015281548/
 * Language: cpp
 * Date: 2026-05-28
 */

class MinStack {
    
    stack<int> st;
    stack<int> minSt;

public:

    MinStack() {
        
    }
    
    void push(int val) {

        st.push(val);

        // Push in min stack if minimum
        if(minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {

        if(st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
