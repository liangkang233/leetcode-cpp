/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 类似55题的贪心
    int jump(vector<int>& nums) {
        int ans = 0, maxn = nums[0], last = 0;  //last表示为上一个的落脚点
        for (int i = 0; i < nums.size() - 1; i++) { //题中说明必定可以到达终点
            maxn = max(i+nums[i], maxn);
            if (maxn >= nums.size() - 1)
                return ans + 1;            
            if (i == last) {
                last = maxn;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

// 还是从队头开始的贪心 好些   二刷
// 和55的跳跃游戏类似, 如果用动态规划做，从数组尾部记录开始记录能到达的最小跳数 dp[i]
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, i = 0, j = 0, maxn = nums[0]; // i为遍历下标 j为该次跳跃最大下标 maxn为该次跳跃的最大值
        while(1) {
            if(i >= nums.size()-1 || i > j) break;
            maxn = max(maxn, i + nums[i]);
            if(i == j) {
                j = maxn;
                ans++;
            }
            i++;
        }
        return i > j ? -1 : ans; //-1表示不能跳跃到最后一个位置 虽然题目没给这样的案例
    }
};
// [0,1,1,0]\n
// [2,3,0,1,4]\n
// [0]
// [2,3,1,1,4,6,7,3,1,1,1,6]\n