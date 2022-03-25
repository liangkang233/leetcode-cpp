/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 一眼二分 求所需值的左右边界
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        int start = 0, end = nums.size()-1;
        if (end < 0)
            return ans;
        // 左边界
        while (start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] < target)
                start = mid+1;
            else 
                end = mid-1;
        }
        if(start < nums.size() && nums[start] == target)
            ans[0] = start;
        start = 0, end = nums.size()-1;
        // 右边界
        while (start <= end) {
            int mid = (start + end) / 2;
            if(nums[mid] <= target)
                start = mid+1;
            else 
                end = mid-1;
        }
        if (end >= 0 && nums[end] == target)
            ans[1] = end;
        return ans;
    }
};
// @lc code=end


// 二刷
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 使用lower_bound upper_bound 来做
        auto start = lower_bound(nums.begin(), nums.end(), target);
        if(start==nums.end() || *start > target)
            return vector<int>(2, -1);
        else {
            auto end = upper_bound(nums.begin(), nums.end(), target) - 1;
            return vector<int>{(int)distance(nums.begin(), start), (int)distance(nums.begin(), end)};
        }
    }
};
