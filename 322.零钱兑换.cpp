/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
// 还记得是来实验室做的第一道动态规划 梦开始的地方
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                int coin = coins[j];
                if(i-coin >= 0 && dp[i-coin] >= 0)
                    dp[i] = min(dp[i-coin] + 1, dp[i]);
            }
            if(dp[i]==INT_MAX)
                dp[i] = -1;
            // cout << i << " " << dp[i] << endl;
        }
        return dp.back();
    }
};
// @lc code=end
// [1,2,5]\n1234\n
// [3,9,5]\n1234\n
// [3,9,5,2,14,2]\n9999\n

// 二刷 此题即为完全01背包问题 变形
// 背包问题总结: https://seramasumi.github.io/docs/Algorithms/mc-%E5%BE%AE%E8%AF%BE%E5%A0%82-%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98.html
// 常规 01 背包 i j 遍历  优化为1维 需要 j 逆序      i 为背包种类 j 为背包上限
// 多重 01 背包 i j k 遍历 优化为1维 需要 j 逆序     i 为背包种类 j 为背包上限 k为对应背包可以出现的个数
// 完全 01 背包 i j 遍历  优化为1维 需要 j 正序      i 为背包种类 j 为背包上限
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if(i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        return dp[amount]==INT_MAX ? -1 : dp[amount];
    }
};

// 三刷
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if(i-coins[j] < 0)
                    break;
                else if(dp[i-coins[j]] < 0)
                    continue;
                if(dp[i] == -1)
                    dp[i] = dp[i-coins[j]] + 1;
                else
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
        return dp[amount];
    }
};
