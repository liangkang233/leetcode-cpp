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
