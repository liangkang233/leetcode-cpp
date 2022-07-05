// https://www.nowcoder.com/practice/28970c15befb4ff3a264189087b99ad4?tpId=295&tags=&title=&difficulty=0&judgeStatus=0&rp=0&sourceUrl=%2Fexam%2Foj

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
     * @param str string字符串 
     * @param pattern string字符串 
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        vector<vector<bool>> dp(str.size() + 1, vector<bool>(pattern.size()+1, false));
        dp[0][0] = true;
        auto isok = [&str, &pattern](int x, int y) {
            x--, y--;
            if((x >= 0) && (pattern[y] == '.' || pattern[y] == str[x]))
                return true;
            return false;
        };
        for (int i = 0; i <= str.size(); i++) {
            for (int j = 1; j <= pattern.size(); j++) {
                if(pattern[j-1] == '*') {
                    if(isok(i, j-1))
                        dp[i][j] = dp[i-1][j] || dp[i][j-2];
                    else
                        dp[i][j] = dp[i][j-2];
                } else {
                    if(isok(i, j))
                        dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp.back().back();
    }
};