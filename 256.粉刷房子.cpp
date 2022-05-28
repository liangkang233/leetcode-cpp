/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * plus 会员 https://leetcode.cn/problems/paint-house/ 
 * 
 * https://leetcode.cn/problems/JEj789/
 * 
 * [255] 粉刷房子
 */


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // vector<vector<int>> dp = costs; // dp[i][j]代表i个长度的尾部颜色为j的最小花费
        vector<int> dp(costs.front().begin(), costs.front().end()); // 压缩为一维
        for (int i = 1; i < costs.size(); i++) {
            vector<int> temp = dp;
            for (int j = 0; j < 3; j++) {
                temp[j] = costs[i][j] + min(dp[(j+1)%3], dp[(j+2)%3]);
            }
            swap(temp, dp);
        }
        int ans = min(min(dp[0], dp[1]), dp[2]);
        return ans;
    }
};
// @lc code=end
// [[7,6,2],[17,2,17],[16,16,5],[14,3,19],[7,22,17],[116,146,52],[14,37,191]]

