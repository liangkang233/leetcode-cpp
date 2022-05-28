/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

#include<iostream>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> myarry(m,vector<int>(n, 0));
        copy(grid.begin(), grid.end(), myarry.begin());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int temp1 = INT_MAX, temp2 = INT_MAX;
                if(i==0 && j==0)
                    continue;
                if(i > 0) 
                    temp1 = myarry[i-1][j];
                if(j > 0) 
                    temp2 = myarry[i][j-1];
                myarry[i][j] += min(temp1, temp2);
            }
        }
        return myarry[m-1][n-1];
    }
};
// @lc code=end



// 二刷

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid.front().begin(), grid.front().end()); // 压缩至一维
        for(int i = 1; i < grid[0].size(); i++) // 第一行初始值
            dp[i] += dp[i-1];
        for (int i = 1; i < grid.size(); i++) {
            dp[0] += grid[i][0]; // dp[i][0]
            for (int j = 1; j < grid[0].size(); j++) {
                dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
                // dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp.back();
    }
};