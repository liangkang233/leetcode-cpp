/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<iostream>
#include<vector>
using namespace std;

// 153题目差不多

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        // 匿名函数用法  这样做可减少内存的拷贝
        auto bin_find = [&](int a, int b) ->int {
            int i;
            while (a <= b) {
                i = (a + b) / 2;
                if (nums[i] < target)
                    a = i + 1;
                else if (nums[i] > target)
                    b = i - 1;
                else
                    return i;
            }
            return -1;
        };

        if (nums[0] <= nums[len - 1]) // <即k==0不转移，=即size==1  (普通二分)
            return bin_find(0, len - 1);

        int a = 0, b = len - 1, i;          // 特殊二分 先找到临界点
        while (a <= b) {
            i = (a + b) / 2;
            if (nums[i] < nums[i + 1]) {
                if (nums[i] >= nums[0])
                    a = i + 1;
                else
                    b = i - 1;
            }
            else
                break;
        }
        if (target < nums[0])
            return bin_find(i + 1, len - 1);
        return bin_find(0, i);
    }
};
// @lc code=end


// 跟官方的思路差不多，不过不用先找到最大临界值再二分 直接进行判断二分 
// 注意 边界 等于 问题
// 二刷
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i <= j) {
            int mid = i+j >> 1;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < nums[j]) { // mid-j 递增
                if(nums[mid] < target && nums[j] >= target)
                    i = mid+1;
                else
                    j = mid-1;
            }
            else { // i-mid 递增
                if(nums[mid] > target && nums[i] <= target)
                    j = mid-1;
                else
                    i = mid+1;
            }
        }
        // return i<nums.size() && nums[i]==target ? -1 : i;
        return -1;
    }
};

// 三刷
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l+r) / 2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < nums[r]) {
                if(target > nums[mid] && target <= nums[r])
                    l = mid+1;
                else
                    r = mid-1;
            } else {
                if(target < nums[mid] && target >= nums[l])
                    r = mid-1;
                else
                    l = mid+1;
            }
        }
        return -1;
    }
};