/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp 记录word2长度为i word2长度i 时返回的最少操作数
        vector<vector<int>> dp(word2.size()+1, vector<int>(word1.size()+1, 0)); 
        for (int i = 0; i <= word2.size(); i++) // 填充初始值
            dp[i][0] = i;
        for (int i = 0; i <= word1.size(); i++)
            dp[0][i] = i;
        for (int i = 1; i <= word2.size(); i++) {
            for (int j = 1; j <= word1.size(); j++) {
                if(word2[i-1] == word1[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else // 下取值 对应 word2 三种情况: 删除一个字符 添加一个字符 替换一个字符
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
            }
        }
        return dp.back().back();
    }
};
// @lc code=end
// ""asjkdfjhijahewiohgakjsdhjkjfaoisejgoiajsdlkgjakljdg"\n"asduighuiqawehfnasjdkhgjk"\n"
