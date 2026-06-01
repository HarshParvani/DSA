/*
 * Problem: 2064. Minimized Maximum of Products Distributed to Any Store
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/submissions/2018980550/
 * Language: cpp
 * Date: 2026-06-01
 */

class Solution {
public:
    
    bool canDistribute(vector<int>& quantities, int n, int maxProducts) {
        long long storesNeeded = 0;

        for (int q : quantities) {
            storesNeeded += (q + maxProducts - 1) / maxProducts; // ceil(q/maxProducts)

            if (storesNeeded > n)
                return false;
        }

        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int low = 1;
        int high = *max_element(quantities.begin(), quantities.end());

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (canDistribute(quantities, n, mid))
                high = mid;      // try smaller maximum
            else
                low = mid + 1;   // need larger maximum
        }

        return low;
    }
};
