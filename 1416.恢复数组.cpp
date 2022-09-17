/*
 * @lc app=leetcode.cn id=1416 lang=cpp
 *
 * [1416] 恢复数组
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;


// 处理边界很头疼 最后还是用 longlong 吧，省的写那些判断条件
// @lc code=start
class Solution {
private:
    const int N = 1e9 + 7;
public:
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            long long val = 0, w = 1; // w 代表当前位数
            for (int j = i-1; j >= 0 && w <= int(1e9); j--, w*=10) {
                if(s[j] == '0') continue; // 子字符首元素不能为0 恰好也能去除单字符为0 的情况
                val += w * (s[j] - '0');
                if(val > k) break;
                dp[i] = (dp[i] + dp[j]) % N;
            }
            // cout << dp[i] << " ";
        }
        return dp.back();
    }
};
// @lc code=end

// "1000"\n10000\n"1234567890"\n90\n"1000"\n10\n"1317"\n2000\n"2020"\n30\n
// "6003422444313003422444313111132566283762260526810599111113256628376226052681059918526204"\n1000000000
// "1000000000000000000000000000000000000000000000000000000"\n123