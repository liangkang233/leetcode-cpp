/*
 * @lc app=leetcode.cn id=688 lang=cpp
 *
 * [688] “马”在棋盘上的概率
 */

#include<iostream>
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 动态规划 dp记录棋盘的每个概率值，然后遍历更新k次棋盘
    double knightProbability(int n, int k, int row, int column) {
        const int t1[] = {1,1,2,2,-1,-1,-2,-2}, t2[] = {2,-2,1,-1,2,-2,1,-1};
        vector<vector<double>> dp(n, vector<double>(n, 1.0));
        for (int count = 0; count < k; count++) {
            vector<vector<double>> temp(n, vector<double>(n, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int p = 0; p < 8; p++) {
                        int ii = i+t1[p], jj = j+t2[p];
                        if(ii>=0 && ii<n && jj>=0 && jj<n)
                            temp[i][j] += 0.125 * dp[ii][jj];
                    }
                }
            }
            dp = temp;
        }
        return dp[row][column];
    }
};
// @lc code=end

// 15\n50\n10\n10\n
// 3\n2\n0\n0\n
// 1\n0\n0\n0\n
