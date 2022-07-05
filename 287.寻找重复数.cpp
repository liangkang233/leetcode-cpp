/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

#include <iostream>
#include <vector>
using namespace std;

// 和448一样的做法
// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[abs(nums[i]) - 1] < 0) {
                ans = abs(nums[i]);
                break;
            } nums[abs(nums[i]) - 1] *= -1;
        }
        for (int i = 0; i < nums.size(); i++) // 还原
            nums[i] = abs(nums[i]);
        return ans;
    }
};
// @lc code=end

