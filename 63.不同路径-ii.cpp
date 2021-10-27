/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

#include <iostream>
#include <vector> 
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> myarray(m, vector<int>(n, 0));
        if (obstacleGrid[0][0])
            return 0;
        myarray[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ( obstacleGrid[i][j] ) continue;
                if ( i > 0 )
                    myarray[i][j] += myarray[i-1][j];
                if ( j > 0 )
                    myarray[i][j] += myarray[i][j-1];
            }
        }
        return myarray[m-1][n-1];
    }
};
// @lc code=end

