/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

// 按照下面的思路 写动态规划 dp[i][0] dp[i][1] 代表i+1长度买卖最大值 0为未持有股票 1持有股票
// 即将状态压缩为两个 今天买入和之前买入但未卖出=>未持有股票：今天卖出和冷冻期=>持有股票
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)  return 0;
        // 0为未持有股票 1持有股票
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = 0;
        dp[1][0] = max(0, prices[1] - prices[0]);
        dp[0][1] = -prices[0];
        dp[1][1] = max(-prices[0], -prices[1]);
        for (int i = 2; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]); // 买有冷却期最快得要等1天
        }
        return dp.back()[0];
    }
};
// @lc code=end
// [1,2,3,0,2,1,2,34,3,5,4,65,6,57,346,45,67,57,4,56,45,6,47,57,5,7,68,98,78,9,78,98,7,0,7,9,78,9,860,8,0]\n

// 压缩空间
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)  return 0;
        // first为未持有股票 second持有股票
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        pair<int, int> last, now, temp;
        last.first = 0, last.second = -prices[0];
        now.first = max(0, prices[1] - prices[0]), now.second = max(-prices[0], -prices[1]);
        for (int i = 2; i < prices.size(); i++) {
            temp = now;
            now.first = max(temp.first, temp.second + prices[i]);
            now.second = max(temp.second, last.first - prices[i]); // 买有冷却期最快得要等1天
            last = temp;
        }
        return now.first;
    }
};


// 记忆化搜索  花钱用负数减去该价格 卖出表示赚钱加上该价格
//  *1、对于同一天中，存在三种状态：
//  *   0: 买入
//  *   1：卖出
//  *   2: 冷冻期
class Solution {
private:
    unordered_map<int, int> mp;
public:
    int dfs(vector<int>& prices, int index, int status) { // status 1为卖 0为买
        if (index >= prices.size()) return 0;
        int in = index + status * 10000;
        if(mp.find(in) != mp.end())
            return mp[in];
        int a = 0, b = 0, c = 0; //定义三个变量，分别记录[不动]、[卖]、[买]
        a = dfs(prices, index + 1,status);
        if (status == 1) {  //递归处理卖的情况 之后为买
            b = dfs(prices, index + 2, 0) + prices[index];
        } else{             //递归处理买的情况 之后为卖
            c = dfs(prices, index + 1, 1) - prices[index];
        }
        //最终结果就是三个变量中的最大值
        mp[in] = max(max(a, b), c);
        return mp[in];
    }

    int maxProfit(vector<int>& prices) {
        return dfs(prices, 0, 0); // 初始状态只能买
    }
};
// [1,2,3,0,2,1,2,34,3,5,4,65,6,57,346,45,67,57,4,56,45,6,47,57,5,7,68,98,78,9,78,98,7,0,7,9,78,9,860,8,0]\n

