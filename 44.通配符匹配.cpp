/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // s为输入测试值,测试是否与p匹配  p,包含a-z ? *
    // 此题与 10.正则表达式匹配.cpp 类似。不过此处通配符是匹配任意一段字符串，且*前可无字符
    // 正则表达式是 *匹配前一个字符N次
    bool isMatch(string s, string p) {
        int sl = s.size(), pl = p.size();
        // dp[i][j] 表示 s的i长度 与 p的j长度 是否匹配 i、j为0表示长度为0的空的字符串
        auto match = [&](int i, int j) -> bool {
            if (i == 0)
                return false;   //进入match判断时必定不为* 所以可以直接return false
            else if (p[j-1] == '?')
                return true;
            return s[i-1] == p[j-1];
        };
        vector<vector<bool>> dp(sl + 1, vector<bool>(pl + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= sl; i++) {
            for (int j = 1; j <= pl; j++) {
                if (p[j-1] == '*')
                    dp[i][j] = dp[i][j-1] || (i>0 && dp[i-1][j]); //等价 *不存在 或者 *前面匹配成功
                else
                    dp[i][j] = match(i, j) && dp[i-1][j-1];
            }
        }

        return dp[sl][pl];
    }
};
// @lc code=end
