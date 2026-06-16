/*
 * Problem: 493. Reverse Pairs
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/reverse-pairs/submissions/2035003267/
 * Language: cpp
 * Date: 2026-06-16
 */

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define oset tree<long, null_type,less_equal<long>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    int reversePairs(vector<int>& nums) {
       oset os;
       int ans=0;
    for(int i= nums.size()-1 ; i>=0   ; i--){
       ans += os.order_of_key(nums[i]);
        os.insert(2L *nums[i]);
    }      
    return ans ;
    }
};
