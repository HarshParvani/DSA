/*
 * Problem: 71. Simplify Path
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/simplify-path/submissions/2023165409/
 * Language: cpp
 * Date: 2026-06-05
 */

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/')
                continue;
            string temp = "";
            while (i < path.length() && path[i] != '/') {
                temp += path[i];
                i++;
            }
            if (temp == "..") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else if (temp == ".") {
                continue;
            } else {
                stk.push(temp);
            }
        }
        if (stk.empty())
            return "/";
        string ans = "";
        while (!stk.empty()) {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
