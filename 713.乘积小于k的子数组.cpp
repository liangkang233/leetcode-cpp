/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// size=n的数组其全部子数组为n*(n+1)/2 找出滑动遍历时 小于k的窗口 记录后缩减该窗口直至小于k
// 记录的左右下标 为i,j 则新的i，j产生的子数组个数为(j-i+1)   (新产生的子数组一定要包含边界i)  如此累加出答案
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0, temp = 1;
        if(k>1) {
            for (int i = 0, j = 0; i < nums.size(); i++) {
                temp *= nums[i];
                while (j <= i, temp >= k) {  // 缩减窗口左边界使得条件不满足
                    temp/=nums[j];
                    j++;
                }
                ans += i - j + 1;
            }
        }
        return ans;
    }
};
// @lc code=end
// [1,2,3]\n0\n
// [1,2,3,12,5,46,568,325,12,525,784,5,7,12,52,73,475,568,35,47]\n23\n

// 二刷
class Solution {
public:
    // 计入每个小于k乘积 中包含最后一个元素的子数组
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0, temp = 1;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            temp *= nums[i];
            while (temp >= k)
                temp /= nums[j++];
            ans += i - j + 1;
        }
        return ans;
    }
};
