/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // int temp = nums[0], temp1 = temp; // 序列临时值 temp, temp1 递增序列
        int temp = nums[0], temp1 = INT_MAX; // 序列临时值 temp, temp1 递增序列
        // 注意temp1初始值 intmax 而不是nums[0], 即第1次初始化必须要有 否则例如 [5,1,6] 错误
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > temp) {
                if(nums[i] > temp1)
                    return true;
                temp1 = nums[i];
            }
            else
                temp = nums[i];
        }
        return false;
    }
};
// @lc code=end

// [5,4,3,2,1]\n
// [1,2,3,4,5]\n
// [1,5,2,3]\n
// [5,1,6]\n
// [0,4,2,1,0,-1,-3]\n
// [1,5,2,0,3]\n
// [5,1,5,5,2,5,4]\n
