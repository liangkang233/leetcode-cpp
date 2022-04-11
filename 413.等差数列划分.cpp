/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 长度为n的等差数组 其包含自身的子数组个数为 1+2+3+...n-3 + n-2 = (n-2)*(n-1)/2 (n>=3)
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        int ans = 0, temp = INT_MAX, count = 2; // 最大次数 临时差值 记录差值相同的个数
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] - nums[i-1] == temp)
                count++;
            else {
                if(count>=3)
                    ans += (count-2)*(count-1)/2;
                temp = nums[i] - nums[i-1];
                count = 2;
            }
        }
        if(count>=3)
            ans += (count-2)*(count-1)/2;
        return ans;
    }
};
// @lc code=end
// [1,2,3]\n
// [1,2,3,3,-1,-5,-9,-11,3,4,324,6,546,6,7,8,98,2,1,1,1,0,-1,-2,-3]\n
// [1]\n
