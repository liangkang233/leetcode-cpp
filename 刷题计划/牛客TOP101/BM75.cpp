// https://www.nowcoder.com/practice/6a1483b5be1547b1acd7940f867be0da?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param str1 string字符串 
     * @param str2 string字符串 
     * @return int整型
     */
    int editDistance(string str1, string str2) {
        vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, INT_MAX));
        for (int i = 0; i <= str2.size(); i++) dp[0][i] = i;
        for (int i = 1; i <= str1.size(); i++) {
            dp[i][0] = i;
            for (int j = 1; j <= str2.size(); j++) {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]); // 对应 增加 删除 修改
                }
            }
        }
        return dp.back().back();
    }
};