/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        // vector<int> dp(s.size()+1, 1); // dp[i] 表示为对应 0-i 的解码方法数量
        int first = 1, second = 1; // 压缩空间 用first second 替代 dp[i-1] dp[i]
        if(s[0] == '0')
            return 0;
        for (int i = 1; i < s.size(); i++) {
            int temp = second;
            if(s[i] == '0') {
                if(s[i-1] != '1' && s[i-1] != '2')
                    return 0;
                temp = first;
            }
            else if( (s[i-1] == '2' && s[i] <= '6' ) || (s[i-1] == '1'))
                temp += first;
            first = second;
            second = temp;
        }
        return second;
    }
};
// @lc code=end
// "0"\n
// "100"\n
// "2101"\n
// "361074512634152910836592081620253897167"\n
// "1278435871261927397518723610745126341520836510816202538971672635105712986571081628935677810165786201"\n


class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 1); // dp[i] 表示为对应 0-i 的解码方法数量
        if(s[0] == '0')
            return 0;
        for (int i = 1; i < s.size(); i++) {
            dp[i+1] = dp[i];
            if(s[i] == '0') {
                if(s[i-1] != '1' && s[i-1] != '2')
                    return 0;
            }
            else if( (s[i-1] == '2' && s[i] <= '6' ) || (s[i-1] == '1')) //前面之所以没合并if项 是得保证这个判断中的s[i]不为0
                dp[i+1] += dp[i-1];
            // cout << i << " " << dp[i+1] << endl;
        }
        return dp.back();
    }
};