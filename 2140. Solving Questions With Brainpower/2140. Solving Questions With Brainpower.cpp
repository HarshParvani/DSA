/*
 * Problem: 2140. Solving Questions With Brainpower
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/solving-questions-with-brainpower/submissions/2034878675/
 * Language: cpp
 * Date: 2026-06-16
 */

class Solution {
public:
    vector<long long> dp;

    long long helper(vector<vector<int>>& questions, int i,vector<long long>&memo) {
        if (i >= questions.size())
            return 0;

        if (memo[i] != -1)
            return memo[i];

        long long skip = helper(questions, i + 1,memo);

        long long pick = questions[i][0] + helper(questions, i + questions[i][1] + 1,memo);

        return memo[i] = max(pick, skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>memo(n,-1);
        return helper(questions, 0,memo);
    }
};
