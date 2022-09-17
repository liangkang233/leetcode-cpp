/*
 * @lc app=leetcode.cn id=1464 lang=cpp
 *
 * [1464] 数组中两元素的最大乘积
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size()-1;
        return (nums[n-1] - 1) * (nums[n] - 1);
    }
};
// @lc code=end


// 一次遍历 维护最大值 次最大值
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a = nums[0], b = nums[1];
        if (a < b) {
            swap(a, b);
        }
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] > a) {
                b = a;
                a = nums[i];
            } else if (nums[i] > b) {
                b = nums[i];
            }
        }
        return (a - 1) * (b - 1);
    }
};