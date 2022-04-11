/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        for (int i = 3; i <= n; i++) {
            int temp = INT_MIN;
            for (int j = 1; j <= i/2; j++) {
                int a = max(dp[j], j), b = max(dp[i-j], i-j);
                temp = max(temp, a*b);
                // temp = max(dp[i], dp[i-j]);
            }
            dp[i] = temp;
        }
        return dp[n];
    }
};
// @lc code=end

// 二刷
class Solution {
public:
    int integerBreak(int n) {
        // 易知 i>2 时 最大乘积 dp[i-1] 一定至少拆解为两个数乘积 返回值就是 dp 其余情况直接 return 1
        // dp[i] 为不包含自身在内的 i 拆分数最大乘积
        vector<int> dp(n, 1); // dp[0] = dp[1] = 1
        for (int i = 2; i < n; i++) {
            for (int j = 0; j < i; j++)
                dp[i] = max(dp[i], (i-j) * max(dp[j], j+1));
        }
        return dp.back();
    }
};

