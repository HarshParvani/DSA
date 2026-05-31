/*
 * Problem: 205. Isomorphic Strings
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/isomorphic-strings/submissions/2018011925/
 * Language: cpp
 * Date: 2026-05-31
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>map(256);
        vector<bool>visited(256);
        for(int i =0;i<s.size();i++){
            if (map[s[i]]==0 && visited[t[i]]==false){
                map[s[i]]=t[i];
                visited[t[i]]=true;
            }
        }
        for(int i=0;i<s.size();i++){
            if(map[s[i]]!=t[i])
            return false;
        }
        return true;
    }
};
