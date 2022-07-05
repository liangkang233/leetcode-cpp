/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/count-square-submatrices-with-all-ones/ 转移方程参考

// @lc code=start
class Solution {
public:
    // 动规压缩空间
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<int> dp(matrix[0].size()+1, 0), temp(dp);
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                if(matrix[i-1][j-1] == '1') {
                    temp[j] = min(dp[j-1],  min(dp[j],  temp[j-1])) + 1;
                    ans = max(ans, temp[j]);
                } else {
                    temp[j] = 0;
                }
            }
            swap(temp, dp);
        }
        return ans*ans;
    }
};
// @lc code=end

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j] 代表 以i-1 j-1 为右下角下标的最大正方形边长 dp[i][j] = min( dp[i-1][j-1],  dp[i-1][j],  dp[i][j-1]);
        int ans = 0;
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0)); // 建立一个初始行 方便遍历
        for (int i = 1; i <= matrix.size(); i++) {
            for (int j = 1; j <= matrix[0].size(); j++) {
                if(matrix[i-1][j-1] == '1') {
                    dp[i][j] = min(dp[i-1][j-1],  min(dp[i-1][j],  dp[i][j-1])) + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};