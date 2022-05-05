/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>>dp; // 动态规划生成一个 二维的前缀数组 dp[i][j] 为 (0, 0) 到 (i, j) 的元素和
    NumMatrix(vector<vector<int>>& matrix) {
        dp = matrix;
        for (int i = 1; i < matrix.size(); i++)
            dp[i][0] += dp[i-1][0];
        for (int j = 1; j < matrix[0].size(); j++)
            dp[0][j] += dp[0][j-1];
        for (int i = 1; i < matrix.size(); i++) {
            int prefix = matrix[i][0];
            for (int j = 1; j < matrix[0].size(); j++) {
                prefix += matrix[i][j];
                dp[i][j] = dp[i-1][j] + prefix;
            }
        }
        // for (auto &&i : dp) {
        //     for (auto &&j : i)
        //         cout << j << " ";
        //     cout << endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int temp = 0, temp1 = 0;
        if(row1 > 0 && col1 > 0) // 补偿用的小矩阵
            temp1 = dp[row1-1][col1-1];
        if(row1 > 0)
            temp += dp[row1-1][col2];
        if(col1 > 0)
            temp += dp[row2][col1-1];
        return dp[row2][col2] + temp1 - temp;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
// ["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
// ["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[0,1,4,3],[2,0,2,2],[0,0,2,4]]
