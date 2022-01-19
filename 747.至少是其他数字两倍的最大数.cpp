/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ans = 0, last = -1; // 最大值下标 last第二大的值 没初始化时为-1
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[ans]) {
                last = nums[ans];
                ans = i;
            }
            else if(nums[i] > last) {
                last = nums[i];
            }
        }
        return nums[ans]>=2*last ? ans : -1;
    }
};
// @lc code=end
// [1,0]\n 返回值是0
// [3,6,4,10,7]\n
