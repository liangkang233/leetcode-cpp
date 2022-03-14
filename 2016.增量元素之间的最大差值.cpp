/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 做两次次遍历记录左边正序数组的最小值 逆序数组的最大值
    int maximumDifference(vector<int>& nums) {
        vector<int> left, right;
        int MAX = 0, MIN = INT_MAX, ans = -1;
        for (int i = 0; i < nums.size(); i++) {
            MIN = min(MIN, nums[i]);
            left.push_back(MIN);
        }
        for (int i = nums.size()-1; i>=0; i--) {
            MAX = max(MAX, nums[i]);
            right.push_back(MAX);
        }
        for (int i = 0; i < nums.size(); i++)
            ans = max(ans, right[nums.size()-i-1] - left[i]);
        return ans==0 ? -1 : ans;
    }
};
// @lc code=end

// [9, 4, 3, 2]\n
// [1, 5, 2, 10]\n

// 前缀最小值
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1, premin = nums[0];
        for (int i = 1; i < n; ++i) {
            if (nums[i] > premin) {
                ans = max(ans, nums[i] - premin);
            } else {
                premin = nums[i];
            }
        }
        return ans;
    }
};