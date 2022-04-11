/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k % n;
        // cout << k << endl;
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+ k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end

// [1,2,3]\n1