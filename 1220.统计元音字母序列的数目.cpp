/*
 * @lc app=leetcode.cn id=1220 lang=cpp
 *
 * [1220] 统计元音字母序列的数目
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    // 动态规划
    const int Y = 1e9 + 7;
    long long dp[5] = {1, 1, 1, 1, 1};
    int countVowelPermutation(int n) {
        for (int k = 1; k < n; k++) {
            long long a = dp[0], e = dp[1], i = dp[2], o = dp[3], u = dp[4];
            dp[0] = (e + u + i) % Y;
            dp[1] = (a + i) % Y;
            dp[2] = (e + o) % Y;
            dp[3] = i % Y;
            dp[4] = (i + o) % Y;
        }
        for (int i = 1; i < 5; i++)
            dp[0] += dp[i];
        return dp[0] % Y;
    }
};
// @lc code=end

// 直接遍历
class Solution {
public:
    // const int Y = 1000000000 + 7;
    const int Y = 1e9 + 7;
    long long a = 1, e = 1, i = 1, o = 1, u = 1;
    int countVowelPermutation(int n) {
        for (int k = 1; k < n; k++) {
            long long aa = a, ee = e, ii = i, oo = o, uu = u;
            a = (ee + uu + ii) % Y;
            e = (aa + ii) % Y;
            i = (ee + oo) % Y;
            o = ii % Y;
            u = (ii + oo) % Y;
        }
        return (a+e+i+o+u) % Y;
    }
};