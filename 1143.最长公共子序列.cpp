/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //dp[i][j]即为 text1 长度为i, text2 长度为j 的最长公共子序列 的长度
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for (int i = 1; i <= text1.size(); i++) {
            for(int j = 1; j <= text2.size(); j++) {
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        // for (auto &&i : dp) {
        //     for (auto &&j : i)
        //         cout << j << " ";
        //     cout << endl;            
        // }
        return dp.back().back();
    }
};
// @lc code=end

// ""aaa"\n"aacde"\n"
// ""asdgkhiqauwheojhasoidgjhikahsdkgjhajsdhgkjhajsdghoiawhklnxdcmkvbnauhidgcuyghsdjkhqwaer"\n"asasdjhgjk"\n"
