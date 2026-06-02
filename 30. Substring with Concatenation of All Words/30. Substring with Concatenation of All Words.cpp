/*
 * Problem: 30. Substring with Concatenation of All Words
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/submissions/2020047947/
 * Language: cpp
 * Date: 2026-06-02
 */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLen = words[0].size();
        int numWords = words.size();
        int totalLen = wordLen * numWords;

        unordered_map<string, int> wordCount;
        for (auto &w : words) wordCount[w]++;

        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            unordered_map<string, int> window;

            for (int right = i; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);

                if (wordCount.find(word) != wordCount.end()) {
                    window[word]++;
                    count++;

                    while (window[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return result;
    }
};

