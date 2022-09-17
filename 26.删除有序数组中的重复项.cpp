/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;
        for(; j < nums.size(); j++) {
            if(nums[j] != nums[i-1]) {
                swap(nums[i], nums[j]);
                i++;
            } 
        }
        return i;
    }
};
// @lc code=end

