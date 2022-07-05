/*
 * @lc app=leetcode.cn id=1175 lang=cpp
 *
 * [1175] 质数排列
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
// 注意 1 不是质数  直接计算n内有多少质数 计算其排列组合即可
class Solution {
public:
    int numPrimeArrangements(int n) {
        int count = n - 1;
        long long ans = 1;
        vector<int> dp(n+1, true);
        for (int i = 2; i <= n/2; i++) {
            for (int j = i+i; j <= n; j+=i) {
                if(dp[j]) {
                    count--;
                    dp[j] = false;
                }
            }
        }
        // cout << count << " " << n - count << endl;
        for (int i = 1; i <= count; i++)
            ans = (ans * i) % (int)(1e9 + 7);
        for (int i = 1; i <= n-count; i++)
            ans = (ans * i) % (int)(1e9 + 7);
        return ans;
    }
};
// @lc code=end
// 1\n3\n67\n99\n