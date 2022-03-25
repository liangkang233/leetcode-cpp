/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 时间复杂度为 O(n)
    int findMin(vector<int>& nums) {
        int temp = nums[0];
        for (auto &&num : nums) {
            if(temp > num)
                return num;
            temp = num;
        }
        return nums[0];
    }
};
// @lc code=end


// 二刷
// 33题差不多

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0, j = (int)nums.size() - 1;
        while (i < j) {
            int mid = i+j >> 1;
            if(nums[mid] < nums[j]) { //mid 到 j 为递增
                j = mid;
            }
            else { // i 到 mid 为递增
                i = mid + 1;
            }
        }        
        return nums[i];
    }
};


// 摸鱼做法 sort 后输出 nums[0]