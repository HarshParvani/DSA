/*
 * Problem: 2516. Take K of Each Character From Left and Right
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/submissions/2020032439/
 * Language: cpp
 * Date: 2026-06-02
 */

class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int>freq(3);
        for(char ch:s){
            freq[ch-'a']++;
        }
        if(*min_element(freq.begin(),freq.end())<k)
        return -1;
        int len=-1;
        for(int left=0,right=0;right<s.size();right++){
            freq[s[right]-'a']--;
            while(*min_element(freq.begin(),freq.end())<k){
                freq[s[left]-'a']++;
                left++;
            }
            len=max(right-left+1,len);
        }
        return s.size()-len;
    }
};
