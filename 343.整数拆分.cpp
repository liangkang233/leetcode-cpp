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

