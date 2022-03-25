/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 题中说明 相邻元素必定不相同 且假设 nums[-1] = nums[n] = -∞
    int findPeakElement(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        if(j == 0 || nums[1] < nums[0])
            return 0;
        if(nums[j-1] < nums[j])
            return j;
        while (i < j) {
            int mid = i + j >> 1;
            // cout <<  mid << " " << i << " " << j << endl;
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]) //mid 必定不为0 无需做判断
                return mid;
            if(nums[mid] <= nums[i])  //左侧必定存在高峰值
                j = mid;
            else if(nums[mid] <= nums[j]) //右侧必定存在高峰值
                i = mid;
            else{ // 左右都有可能 左移一个j 哪怕j不成立 后续的mid也有修改
                j--;
                if(nums[j-1] < nums[j] && (j+1<nums.size() || nums[j] > nums[j+1]))
                    return j;
            }   
        }
        return i;
    }
};
// @lc code=end

// [1,2,1,3,5,6,4]\n
// [1,2,3,4,3]\n