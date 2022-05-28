/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 动态规划
    int minCostClimbingStairs(vector<int>& cost) {
        int last = 0, now = 0; // 可以从 0 1下标出发 即下标花费0
        for (int i = 2; i <= cost.size(); i++) {
            int temp = now;
            now = min(cost[i-1]+now, cost[i-2]+last);
            last = temp;
        }
        return now;
    }
};
// @lc code=end

// [1,100,1,1,1,100,1,1,100,1] 