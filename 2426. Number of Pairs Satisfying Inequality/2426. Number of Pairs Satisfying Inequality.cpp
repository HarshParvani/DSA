/*
 * Problem: 2426. Number of Pairs Satisfying Inequality
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/
 * Language: cpp
 * Date: 2026-06-17
 */

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    typedef tree<pair<long long,int>,null_type,less<pair<long long,int>>,
    rb_tree_tag,tree_order_statistics_node_update> oset;

    long long numberOfPairs(vector<int>& nums1,vector<int>& nums2,int diff) {

        oset os;
        long long ans = 0;

        for(int j = 0; j < nums1.size(); j++) {

            long long cur = (long long)nums1[j] - nums2[j];

            ans += os.order_of_key({cur + diff + 1, -1});

            os.insert({cur, j});
        }

        return ans;
    }
};
