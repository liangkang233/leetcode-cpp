/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <iostream>
#include <vector>
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