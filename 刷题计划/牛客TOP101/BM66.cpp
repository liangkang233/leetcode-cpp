// https://www.nowcoder.com/practice/f33f5adc55f444baa0e0ca87ad8a6aac?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 与 BM65 题不同 子串是要连续的
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        int l1 = str1.size(), l2 = str2.size(), n = 0;
        string ans;
        // vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0)); // dp[i][j] 表示 i-1 j-1 为尾部的匹配字符串长度
        vector<int> dp(l2+1, 0); // 压缩下
        for (int i = 1; i <= l1; i++) {
            for (int j = l2; j >= 0; j--) {
                if(str1[i-1] != str2[j-1]) {
                    dp[j] = 0; // 压缩后必须手动清零
                } else {
                    dp[j] = dp[j-1] + 1;
                }
                dp[j] = dp[j-1] + 1;
                if(dp[j] > n) {
                    n = dp[j];
                    ans = str1.substr(i+1-n, n);
                }
            }
        }
        return ans;
    }
};