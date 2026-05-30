/*
 * Problem: 75. Sort Colors
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/sort-colors/submissions/2017118975/
 * Language: cpp
 * Date: 2026-05-30
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int zero = 0;
        int one = 0;
        int two = nums.size() - 1;

        while(one <= two) {

            if(nums[one] == 1) {
                one++;
            }

            else if(nums[one] == 0) {

                swap(nums[one], nums[zero]);

                one++;
                zero++;
            }

            else {

                swap(nums[one], nums[two]);

                two--;
            }
        }
    }
};
