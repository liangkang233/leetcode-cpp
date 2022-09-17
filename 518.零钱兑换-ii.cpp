/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int j = 0; j < coins.size(); j++) {
            for(int i = coins[j]; i <= amount; i++) {
                dp[i] += dp[i-coins[j]];
            }
        }
        return dp.back();
    }
};
// @lc code=end

