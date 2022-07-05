/*
 * @lc app=leetcode.cn id=730 lang=cpp
 *
 * [730] 统计不同回文子序列
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// @lc code=start
// 三维dp 
class Solution { 
public:
    int countPalindromicSubsequences(string s) {
        const int Y = 1e9 + 7, n = s.size();
        // dp[x][i][j]表示下标 i 到 j 回文串 首字符为 x 的 长度
        // 仔细思考状态一情况下 为什么 + 2 而且不用去重
        // 而且采用 与 5.最长回文子串.cpp 不同的遍历方式 即按照长度
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(n, vector<int>(n, 0)));
        for (int i = 0; i < n; i++) // 确定 长度为1 初始值
            dp[s[i]-'a'][i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0, j = i+len-1; j < n; i++, j++) {
                for (int k = 0; k < 4; k++) {
                    if(s[i] == (k+'a') && s[j] == (k+'a')) {
                        for(int ii = 0; ii < 4; ii++)
                            dp[k][i][j] = (dp[k][i][j] + dp[ii][i+1][j-1]) % Y;
                        dp[k][i][j] += 2;
                    } else if(s[i] == k+'a') {
                        dp[k][i][j] = dp[k][i][j-1];
                    } else if(s[j] == k+'a') {
                        dp[k][i][j] = dp[k][i+1][j];
                    } else {
                        dp[k][i][j] = dp[k][i+1][j-1];
                    }
                    // printf("dp[%d][%d][%d] = %d\n", k, i, j, dp[k][i][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 4; i++) ans = (ans + dp[i][0][n-1]) % Y;
        return ans;
    }
};
// @lc code=end

// 需要好好理解
class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> next(n, vector<int>(4)); // 下个该字符下标
        vector<vector<int>> pre(n, vector<int>(4));  // 上个该字符下标
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        
        vector<int> pos(4, -1);
        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 4; c++) {
                pre[i][c] = pos[c]; // 记录相同值的上个下标 不存在为-1
            }
            pos[s[i] - 'a'] = i;
        }
        pos[0] = pos[1] = pos[2] = pos[3] = n;
        for (int i = n - 1; i >= 0; i--) {
            for (int c = 0; c < 4; c++) {
                next[i][c] = pos[c]; // // 记录相同值的下个下标 不存在为n
            }
            pos[s[i] - 'a'] = i;
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    int low = next[i][s[i] - 'a'];
                    int high = pre[j][s[i] - 'a'];
                    if (low > high) { // i j 区间内没有重复值 即无重复区间  2 + dp[i+1][j-1]*2 假设外层字符为 A 该值代表 A、AA A[i+1, j-1]A [i+1, j-1] 这四种情况
                        dp[i][j] = (2 + dp[i + 1][j - 1] * 2) % MOD;
                    } else if (low == high) { // i j 内有一个重复值 删除 结果中该字符的重复
                        dp[i][j] = (1 + dp[i + 1][j - 1] * 2) % MOD;
                    } else { // i j 内有多个重复值 删除最外层区间的值
                        dp[i][j] = (0LL + dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1] + MOD) % MOD;
                    }
                } else {
                    dp[i][j] = (0LL + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
                }
            }
        }
        return dp[0][n - 1];
    }
};
