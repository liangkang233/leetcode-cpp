/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// 双指针 一个遍历 0 一个遍历非0
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0; // i指向0 j指向非0 所以j一定大于i
        while (i < nums.size() && j < nums.size()) {
            while (i < nums.size() && nums[i] != 0) i++; // 加<size 防止没有0
            while (j < nums.size() && (j <= i || nums[j] == 0)) j++;
            if(j < nums.size())
                swap(nums[i], nums[j]);
            ++i, ++j;
        }
    }
};
// @lc code=end
// [1,3,0,0,0,0,0,23,8,9,0,2,4,0]\n
// [1,30,23,545]\n

// 优雅的双指针 牛的 不用swap
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        // 将所有非零元素向前移动
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i]; // j为上一个不为0的值
            }
        }
        for (;j < nums.size(); j++) {
            nums[j] = 0;
        }
    }
};

