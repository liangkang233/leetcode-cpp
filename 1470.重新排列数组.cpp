/*
 * @lc app=leetcode.cn id=1470 lang=cpp
 *
 * [1470] 重新排列数组
 */


#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums.size());
        for(int i = 0, j = nums.size()/2, k = 0; i < nums.size()/2; i++, j++) {
            ans[k++] = nums[i];
            ans[k++] = nums[j];
        }
        return ans;
    }
};
// @lc code=end

