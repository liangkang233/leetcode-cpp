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

// 二刷还是忘 超
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0)); // dp[i][j] 表示 text1 长度为i text2长度为j 的最大子序列长度
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

// 压缩至一维
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        int tl1 = text1.size(), tl2 = text2.size();
        vector<int> dp(tl2+1, 0), temp(dp);
        for (int i = 1; i <= tl1; i++) {
            for (int j = 1; j <= tl2; j++) {
                if(text1[i-1] == text2[j-1])
                    temp[j] = dp[j-1] + 1;
                else
                    temp[j] = max(temp[j-1], dp[j]);
            }
            swap(temp, dp);
        }
        return dp[tl2];
    }
};