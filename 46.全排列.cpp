/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 全不相同，直接递归回溯
    vector<vector<int>> ans;
    void my_permutation(vector<int>& nums, int start) {
        if (start >= nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);          
            my_permutation(nums, start+1);  //注意 是start+1传进去 非i+1
            swap(nums[i], nums[start]);
        } 
    }

    vector<vector<int>> permute(vector<int>& nums) {
        my_permutation(nums, 0);
        return ans;
    }
};
// @lc code=end