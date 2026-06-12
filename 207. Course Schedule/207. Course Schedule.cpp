/*
 * Problem: 207. Course Schedule
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/course-schedule/submissions/2030575711/
 * Language: cpp
 * Date: 2026-06-12
 */

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        vector<int> indegree(numCourses, 0);

        for(auto edge : prerequisites) {

            int course = edge[0];
            int prereq = edge[1];

            adj[prereq].push_back(course);

            indegree[course]++;
        }
        queue<int> q;

        for(int i = 0; i < numCourses; i++) {

            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            count++;

            for(auto nbr : adj[node]) {

                indegree[nbr]--;

                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        return count == numCourses;
    }
};
