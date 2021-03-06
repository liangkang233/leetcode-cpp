/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        // vector<int>dp(s.size()+1, 0); // dp[i] 表示第i个位置之后全为1   压缩为单个变量
        int dp = 0;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == '0')
                dp++;
        }
        int ans = dp;
        for (int i = 1; i <= s.size(); i++) {
            if(s[i-1] == '0')
                dp--;
            else
                dp++;
            ans = min(ans, dp);
        }
        return ans;
    }
};
// @lc code=end
// "010101010101001010111110000010101001010100001010101010101010"\n

// 二刷
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ans = INT_MAX, n = 0; 
        for (int i = 0; i < s.size(); i++) { // 计算全1数量
            if(s[i] == '0') n++;
        }
        for (int i = 0; i < s.size(); i++) { // i 代表从下标i开始为字符全为1
            if(s[i] == '0')
                n--;
            else
                n++;
            ans = min(ans, n);
        }
        return ans;
    }
};