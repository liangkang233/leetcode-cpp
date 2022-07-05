/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 将数字循环 转为 乘积倍数 循环
// 0 1 2 3 4 5
// 1 2 3 4 5 0 => 上式加前缀和: 1 2 3 4 5 6 - 6*n[5]
// 2 3 4 5 0 1 => 上式加前缀和: 2 3 4 5 0 1 - 6*n[4]
// 3 4 5 0 1 2 => 上式加前缀和: 3 4 5 0 1 2 - 6*n[3]

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), pre = nums[0], ans = 0, temp = 0;
        for (int i = 1; i < n; i++) pre += nums[i]; // 前缀和
        for (int i = 1; i < n; i++) ans += i * nums[i];
        temp = ans;
        for (int i = n-1; i > 0; i--) {
            temp += pre - n * nums[i];
            ans = max(ans, temp);
        }
        return ans;
    }
};
// @lc code=end
// [23,7,86,47,81,62,83,65,81,26,78,61,8,2,3,7,8,9,5,7,1,2,3,8,7,65,7,6,3,2,5,6,7,9]\n
