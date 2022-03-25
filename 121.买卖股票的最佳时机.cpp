/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp可以不需要 直接用一个最大值记录
        vector<int> dp(prices.size()+1, 0); // dp[i] 表示prices长度为i 输出的最大值
        int minx = prices[0]; // 数据组中最小值
        for (int i = 0; i < prices.size(); i++) {
            if(prices[i] - minx > dp[i])
                dp[i+1] = prices[i] - minx;
            else{
                minx = min(prices[i], minx);
                dp[i+1] = dp[i];
            }
        }
        return dp[prices.size()];
    }
};
// @lc code=end

// [4,3,2,1]\n
// [2,4,1]\n