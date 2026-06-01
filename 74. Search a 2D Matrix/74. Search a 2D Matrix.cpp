/*
 * Problem: 74. Search a 2D Matrix
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/search-a-2d-matrix/submissions/2018891142/
 * Language: cpp
 * Date: 2026-06-01
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int i = mid / n;
            int j = mid % n;

            if (matrix[i][j] == target)
                return true;

            if (target < matrix[i][j])
                high = mid - 1;
            else
                low = mid + 1;
        }

        return false;
    }
};
