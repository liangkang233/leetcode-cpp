/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
// 由于输入数据为非负整数 必然间隔一个数的答案最大 计算奇数偶数和 
// 这种贪心思路是错的 也许最大值是一部分奇数和与一部分偶数和


// 使用动态规划 dp[i] 为取到 i下标 的最大数据 
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        if(nums.size() == 1)
            return nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int temp1 = i-2>=0 ? dp[i-2] : 0;
            int temp2 = i-3>=0 ? dp[i-3] : 0;
            dp[i] = nums[i] + max(temp1, temp2);
        }
        return max(dp.back(), *(dp.rbegin()+1));
    }
};
// @lc code=end
// [0]\n
// [2,7,9,3,1]\n
// [2,7,9,3,1,12,5,90,3,8,234,56,34,63,45,55,75,93,47,95,9]\n


// 这里写的还是不太好 dp[i]应该设置为i为下标的最大数据 不一定取到i
// 好好思考为什么 下面式子一定成立 举几个例子
// dp[i]=max(dp[i−2]+nums[i],dp[i−1])  看看官方的
// 无需记录整个数组，节约了不少空间
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int size = nums.size();
        if (size == 1) {
            return nums[0];
        }
        int first = nums[0], second = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};
