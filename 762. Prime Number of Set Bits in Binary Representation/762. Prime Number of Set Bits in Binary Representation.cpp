/*
 * Problem: 762. Prime Number of Set Bits in Binary Representation
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/submissions/2030679875/
 * Language: cpp
 * Date: 2026-06-12
 */

class Solution {
public:
    int countPrimeSetBits(int left, int right) {

        unordered_set<int> prime =
        {2,3,5,7,11,13,17,19};

        int ans = 0;

        for(int i = left; i <= right; i++) {

            if(prime.count(__builtin_popcount(i)))
                ans++;
        }

        return ans;
    }
};
