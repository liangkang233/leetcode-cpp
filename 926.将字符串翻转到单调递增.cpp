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
