/*
 * Problem: 2418. Sort the People
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/sort-the-people/submissions/2019953261/
 * Language: cpp
 * Date: 2026-06-02
 */

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& h) {
        map<int,string,greater<int>>map;
        for(int i=0;i<names.size();i++){
            map[h[i]]=names[i];
        }
        vector<string>ans;
        for(auto i:map){
            ans.push_back(i.second);
        }
        return ans;
    }
};
