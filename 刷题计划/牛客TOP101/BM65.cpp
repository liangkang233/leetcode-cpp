// https://www.nowcoder.com/practice/6d29638c85bb4ffd80c020fe244baf11?tpId=295&tqId=991075&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 由于题中使用 string 二维会超出空间 压缩至一维
class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string LCS(string s1, string s2) {
        vector<string> dp(s2.size()+1, ""), temp(dp); // dp[i][j]代表 i长度s1 j长度s2 最大长度子序列
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if(s1[i-1] == s2[j-1]) {
                    temp[j] = dp[j-1] + s1[i-1];
                }
                else if(temp[j-1].size() >= dp[j].size()) {
                    temp[j] = temp[j-1];
                } else {
                    temp[j] = dp[j];
                }
            }
            swap(temp, dp);
        }
        return dp.back() == "" ? "-1" : dp.back();
    }
};


class Solution {
public:
    string LCS(string s1, string s2) {
        vector<vector<string>> dp(s1.size()+1, vector<string>(s2.size()+1, "")); // dp[i][j]代表 i长度s1 j长度s2 最大长度子序列
        // dp[1][1] = s1[0] == s2[0] ? string(1, s1[0]) : "";
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + s1[i-1];
                }
                else if(dp[i][j-1].size() >= dp[i-1][j].size()) {
                    dp[i][j] = dp[i][j-1];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp.back().back() == "" ? "-1" : dp.back().back();
    }
};

