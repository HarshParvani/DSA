/*
 * Problem: 210. Course Schedule II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/course-schedule-ii/submissions/2030585509/
 * Language: cpp
 * Date: 2026-06-12
 */

class Solution {
public:
    vector<int> findOrder(int n,
                          vector<vector<int>>& p) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto e : p) {

            int course = e[0];
            int prereq = e[1];

            adj[prereq].push_back(course);

            indegree[course]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()) {

            int curr = q.front();
            q.pop();

            ans.push_back(curr);

            for(auto neigh : adj[curr]) {

                indegree[neigh]--;

                if(indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        if(ans.size() == n) {
            return ans;
        }

        return {};
    }
};
