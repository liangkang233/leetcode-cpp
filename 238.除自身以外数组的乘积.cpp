/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
// 题目要求不使用除法 而且除法有可能计算途中失去精度
// 常规做法 统计 前缀乘 数组，后缀乘法数组。  此处直接在ans上修改 使用临时变量 temp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) // 不包含i的前缀乘积
            ans[i] = ans[i-1] * nums[i-1];
        int temp = 1;
        for (int i = nums.size()-2; i >= 0; i--) { // 不包含i的后缀乘积
            temp *= nums[i+1];
            ans[i] *= temp;
        }
        return ans;
    }
};
// @lc code=end
// [1,4,7,-6,-4,4,3,3]

// 少进行一次遍历
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n, 1);
        int prefix = 1, suffix = 1;
        for(int i = 0; i < n; i++){
            ans[i] *= prefix;
            ans[n-i-1] *= suffix;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
        }
        return ans;
    }
};