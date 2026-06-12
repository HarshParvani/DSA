/*
 * Problem: 2220. Minimum Bit Flips to Convert Number
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/submissions/2030658361/
 * Language: cpp
 * Date: 2026-06-12
 */

class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start^goal);
    }
};
