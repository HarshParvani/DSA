/*
 * Problem: 295. Find Median from Data Stream
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/find-median-from-data-stream/submissions/2034908825/
 * Language: cpp
 * Date: 2026-06-16
 */

class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {}

    void addNum(int num) {
        left.push(num);

        right.push(left.top());
        left.pop();

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() > right.size())
            return left.top();

        return ((double)left.top() + right.top()) / 2.0;
    }
};
