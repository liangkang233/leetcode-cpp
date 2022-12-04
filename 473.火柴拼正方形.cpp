/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */

#include <iostream>
#include <vector>
using namespace std;

// 即为等分四部分 698退化题
// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int q = 0;
        sort(matchsticks.begin(), matchsticks.end());
        for(auto m : matchsticks) q += m;
        if(q % 4 || matchsticks.back() > q / 4) return false;
        q /= 4;
        // cout << q << endl;
        int n = 1 << matchsticks.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] < 0) continue;
            for (int j = 0; j < matchsticks.size(); j++) {
                int new_i = i | (1 << j);
                if((i >> j) & 1 || dp[new_i] > 0) continue;
                if(dp[i] % q + matchsticks[j] > q) break; // 当前j超出值范围 后面就一定不用遍历了
                dp[new_i] = dp[i] + matchsticks[j];
            }
        }
        // for(auto i : dp) cout << i << " ";
        return dp.back() > 0;
    }
};
// @lc code=end

