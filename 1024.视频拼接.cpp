/*
 * @lc app=leetcode.cn id=1024 lang=cpp
 *
 * [1024] 视频拼接
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    // 贪心 设置maxn数组，maxn[i]表示以i为左端点的子区间的最右端点
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> maxR(time, 0);
        for (auto &&clip : clips) {
            if (clip[0] < time)
                maxR[clip[0]] = max(maxR[clip[0]], clip[1]);
        }
        int ans = 0, end = 0, R = 0;
        for (int i = 0; i < time; i++) {
            R = max(R, maxR[i]);
            if(i == R)
                return -1;
            if(i == end) {
                end = R;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end

    // 动态规划：dp[i]表示时间从0-i最少需要几个片段  dp[i]默认初始化为INT_MAX-1
    // 转换规则: for计算dp[i] 遍历区间clips，如果子区间(a,b) 那么dp[i] = dp[a] + 1
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<int> dp(time+1, INT_MAX-1); //dp[i]表示时间从0-i最少需要几个片段   
        // 注意 这里dp的最大值不要取intmax，否则下面dp[clip[0]] + 1可能会超出int大小
        dp[0] = 0;
        for (int i = 1; i <= time; i++) {
            for (auto && clip : clips) {
                if (clip[0] < i && clip[1] >= i) {
                    dp[i] = min(dp[i], dp[clip[0]] + 1);
                }
            }
        }
        return dp[time]==INT_MAX-1 ? -1 : dp[time];
    }