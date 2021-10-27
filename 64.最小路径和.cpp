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

