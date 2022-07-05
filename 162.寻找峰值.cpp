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


/* 由于起点终点为 负无穷 所以必定有高峰 目标是寻找序列中下降点，序列从左到右
且题意说明 nums[i] != nums[i+1]
从左到右是从“不满足”状态到“满足”状态的。如果nums[mid] < nums[mid+1]，说明仍然不满足，
不必包含mid，继续向右找，即l = mid +1；如果nums[mid] > nums[mid+1]，
说明此时这个mid位置满足了，但不一定是第一个满足的，所以要把mid包含在内，向左找，
即r = mid；退出条件是l == r，
也就是框出了唯一的一个位置，此时退出，返回l即可。这是一个很经典的二分框架～
*/
// 绝了
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] < nums[mid+1])
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};